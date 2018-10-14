/*******************************************************************
*    COPYRIGHT            :    深圳市讯方通信技术有限公司
*******************************************************************/
#include "13_56M.h"


u8 err;
#define OS_ERR_NONE	 1



extern const u16 x_base;
extern const u16 y_base;
volatile u16 Timer1;
u8 tmpUidBuf[5]= {0};

static s8 MFRC_AppReset(void);
static uint8_t MFRC500_RdReg(uint8_t addr);
static void SetADxOutput(void);
static void SetADxInput(void);
static void SetData(uint8_t tmpDat);
static s8 MFRC500_Reset(void);
static uint8_t GetData(void);
static void MFRC500_Config(void);
static void MFRC500_WrReg( uint8_t addr, uint8_t data );
static void MFRC500_ClrBitMask( uint8_t reg, uint8_t mask );
static void MFRC500_SetBitMask( uint8_t reg, uint8_t mask );
static void MFRC500_PwdConvert( uint8_t * key );

/*******************************************************************
*    Function Define Section
*******************************************************************/
void NOP_Dalay(u8 data)
{
    for( ; data>0; data-- )
    {
        __nop();
    }
}

void SysTickDelay(u16 dly_ms)
{
    Timer1=dly_ms;
    while(Timer1);
}

void SysTick_Handler(void)
{
    if(Timer1)
        Timer1--;
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line9) != RESET)
    {
        /* Clear SC EXTIT Line Pending Bit */
        EXTI_ClearITPendingBit(EXTI_Line9);
        err=1; /*  Send IRQ sem  */
    }
}
/*****************************************************************
*    Function Name           :   MFRC_Init
*																 芯片初始化
*    Parameters              :
*
*    Description             :
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
void MFRC_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    //============================================================
    //  GPIOG clock enable
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOG|RCC_APB2Periph_AFIO, ENABLE);
    //  control port
    GPIO_InitStructure.GPIO_Pin = 0x003B<<7;                        // PG7-PG12 没有PG9
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	            //  推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	            //  50M时钟速度
    GPIO_Init(MFRC500_GPIOG, &GPIO_InitStructure);
    //  data port
    GPIO_InitStructure.GPIO_Pin = 0x00FF<<3;                        //  PD3 - PD10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	            //  推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	            //  50M时钟速度
    GPIO_Init(MFRC500_GPIOD, &GPIO_InitStructure);

    MFRC500_ALE_CLR();                                              //  control pins initialize
    MFRC500_PD_CLR();
    MFRC500_CS_SET();
    MFRC500_WR_SET();
    MFRC500_RD_SET();
    //------------------------------------------------------------
    //  IRQ  PG9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	            //  pull-up input
    GPIO_Init(MFRC500_GPIOG, &GPIO_InitStructure);
    //------------------------------------------------------------
    // 连接IO口到中断线
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource9);
    // 配置中断线9为下降沿触发
    EXTI_InitStructure.EXTI_Line = EXTI_Line9;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);


    //============================================================
    // 配置中断使用组合1
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    // EXTI12,13,14,15
    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    if (SysTick_Config(SystemCoreClock / 1000))
    {
        /* Capture error */
        while (1);
    }
    MFRC500_Reset();
    MFRC500_Config();
//			 MFRC_AppReset();   //该函数包含了上面两个函数reset和config。


}

/*****************************************************************
*    Function Name           :   SetADxInput
*
*    Parameters              :
*
*    Description             :
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void SetADxInput(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    //============================================================
    //  data port
    GPIO_InitStructure.GPIO_Pin = 0x00FF<<3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	            //  pull-up
    GPIO_Init(MFRC500_GPIOD, &GPIO_InitStructure);

    NOP_Dalay(16);                                                  //  wait
}
/*****************************************************************
*    Function Name           :   SetADxOutput
*
*    Parameters              :
*
*    Description             :
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void SetADxOutput(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    //============================================================
    //  data port
    GPIO_InitStructure.GPIO_Pin = 0x00FF<<3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	            //  推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	            //  50M时钟速度
    GPIO_Init(MFRC500_GPIOD, &GPIO_InitStructure);
    NOP_Dalay(16);                                                  //  wait
}

/*****************************************************************
*    Function Name           :   MFRC500_PwdConvert
*
*    Parameters              :
*
*    Description             :   密码转换成MF500密码的格式
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
void MFRC500_PwdConvert( uint8_t * key )
{
    uint8_t i, m, tmpval[12] = { 0 };

    for( i = 0; i < 6; i ++ )
    {
        m = * ( key + i ) >> 4 & 0x0F;
        tmpval[i * 2] = ~ m << 4 & 0xF0 | m;
        m = * ( key + i ) & 0x0F;
        tmpval[i * 2 + 1] = ~ m << 4 & 0xF0 | m;
    }
    for( i = 0; i < 12; i ++ )
    {
        * ( key + i ) = tmpval[i];
    }
}

/*****************************************************************
*    Function Name           :   MFRC500_SetBitMask
*
*    Parameters              :   uint8_t reg
*                                uint8_t mask
*    Description             :
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
void MFRC500_SetBitMask( uint8_t reg, uint8_t mask )
{
    uint8_t val;
    val = MFRC500_RdReg( reg );
    MFRC500_WrReg( reg, val | mask );
}

/*****************************************************************
*    Function Name           :   MFRC500_ClrBitMask
*
*    Parameters              :   uint8_t reg
*                                uint8_t mask
*    Description             :   进行寄存器位操作
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
void MFRC500_ClrBitMask( uint8_t reg, uint8_t mask )
{
    uint8_t val;
    val = MFRC500_RdReg( reg );
    MFRC500_WrReg( reg, val & ~ mask );
}


/*****************************************************************
*    Function Name           :   MFRC500_Wr
*																 写寄存器
*    Parameters              :   uint8 reg
*                                uint8 val
*    Description             :
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
void MFRC500_WrReg( uint8_t addr, uint8_t data )
{
    MFRC500_ALE_CLR();                                              //  control pins initialize
    MFRC500_CS_SET();
    MFRC500_WR_SET();
    MFRC500_RD_SET();
    //------------------------------------------------------------
    SetADxOutput();                                                 //  set bus output
    SetData(addr);                                                  //  set Addr
    NOP_Dalay(8);                                                   //  wait
    MFRC500_ALE_CLR();                                              //  lock addr
    NOP_Dalay(8);
    MFRC500_ALE_SET();
    NOP_Dalay(8);
    MFRC500_ALE_CLR();
    NOP_Dalay(8);
    MFRC500_CS_CLR();                                               //  chip select
    NOP_Dalay(4);
    SetData(data);
    NOP_Dalay(8);
    MFRC500_WR_CLR();
    NOP_Dalay(24);
    MFRC500_WR_SET();
    NOP_Dalay(4);
    MFRC500_CS_SET();                                               //  release
    NOP_Dalay(32);
}
/*****************************************************************
*    Function Name           :   MFRC500_RdReg
*
*    Parameters              :
*
*    Description             :
*
*    Returns                 :   uint8_t
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
uint8_t MFRC500_RdReg(uint8_t addr)
{
    uint8_t tmpDat = 0;
    SetADxOutput();                                                 //  set bus output
    SetData(addr);                                                  //  set Addr
    NOP_Dalay(8);
    MFRC500_ALE_CLR();                                              //  lock addr
    NOP_Dalay(8);
    MFRC500_ALE_SET();
    NOP_Dalay(8);
    MFRC500_ALE_CLR();
    NOP_Dalay(8);

    SetADxInput();                                                  //  set bus input
    MFRC500_CS_CLR();                                               //  chip select
    NOP_Dalay(4);

    MFRC500_RD_CLR();
    NOP_Dalay(20);
    tmpDat =  GetData();
    MFRC500_RD_SET();
    NOP_Dalay(4);
    MFRC500_CS_SET();                                               //  release
    NOP_Dalay(32);
    return tmpDat;
}
/*****************************************************************
*    Function Name           :   SetData
*
*    Parameters              :   uint8_t tmpDat  the data need set
*                                                to the pins
*    Description             :
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void SetData(uint8_t tmpDat)
{
    MFRC500_ADX_SETDATA(tmpDat);
}
/*****************************************************************
*    Function Name(函数名)   :   GetData()
*
*    Parameters(参数)        :
*
*    Description(描述)       :
*
*    Returns(返回值)         :
*
*    Global Variable
*    全局变量                :
*    File Static Variable
*    本文件静态变量          :
*    Function Static Variable
*    函数静态变量            :
*----------------------------------------------------------------
*    Revision History(修改历史记录)
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static uint8_t GetData(void)
{
    uint8_t tmp=0;
    tmp = MFRC500_ADX_GETDATA();
    return tmp;
}
/*****************************************************************
*    Function Name(函数名)   :   MFRC500_Reset()
*
*    Parameters(参数)        :
*
*    Description(描述)       :
*
*    Returns(返回值)         :
*
*    Global Variable
*    全局变量                :
*    File Static Variable
*    本文件静态变量          :
*    Function Static Variable
*    函数静态变量            :
*----------------------------------------------------------------
*    Revision History(修改历史记录)
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_Reset(void)
{
    s8 tmpR=0;
    //============================================================
    MFRC500_PD_SET();                                               //  hard reset
    SysTickDelay(10);
    MFRC500_PD_CLR();                                               //  finish reset
    while( (MFRC500_RdReg( RegCommand ) & 0x3F) != 0x3F );          //  wait startup cmd
    while( !(( MFRC500_RdReg( RegCommand ) & 0x3F ) == 0 ) );       //  wait startup cmd finish excuting
    MFRC500_WrReg( RegPage, 0x80 );                                 //  initialize the microprocessor interface
    while( MFRC500_RdReg( RegCommand ) != 0 );                      //  wait
    MFRC500_WrReg( RegPage, 0x00 );                                 //  active linear addressing mode
    tmpR = MFRC500_RdReg(RegCommand);
    if( tmpR !=0 )
    {
        tmpR = -1;
    }
    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_Config
*
*    Parameters              :
*
*    Description             :   将读头配置为所需参数
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void MFRC500_Config(void)
{
    MFRC500_WrReg( RegClockQControl, 0x00 );
    MFRC500_WrReg( RegClockQControl, 0x40 );
    SysTickDelay(10);
    MFRC500_ClrBitMask( RegClockQControl, 0x40 );

    MFRC500_WrReg( RegBitPhase, 0xAD );
    MFRC500_WrReg( RegRxThreshold, 0xFF );
    MFRC500_WrReg( RegRxControl2, 0x01 );
    MFRC500_WrReg( RegFIFOLevel, 0x04 );
    MFRC500_WrReg( RegTimerControl, 0x02 );
    //  cmos output and inverted
    MFRC500_WrReg( RegIrqPinConfig, 0x03 );
    //  TX2RFEn TX1RFEn
    MFRC500_ClrBitMask( RegTxControl, 0x03 );
    SysTickDelay(10);
    MFRC500_SetBitMask( RegTxControl, 0x03 );                       //  TX2RFEn  TX1RFEn
//	MFRC500_WrReg( RegCWConductance, 0x3f );						//
    MFRC500_WrReg( RegMfOutSelect, 0x02 );                          //  modulation signal (envelope) from the internal encoder
}
/*****************************************************************
*    Function Name           :   MFRC500_FindCardCmd
*
*    Parameters              :
*
*    Description             :   发出寻卡命令
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void MFRC500_FindCardCmd(void)
{
    MFRC500_WrReg( RegChannelRedundancy, 0x03 );                    //  RxCRC and TxCRC disable, parity enable
    MFRC500_ClrBitMask( RegControl, 0x08 );                         //  disable crypto 1 unit
    MFRC500_WrReg( RegBitFraming, 0x07 );                           //  set TxLastBits to 7
    MFRC500_SetBitMask( RegTxControl, 0x03 );                       //  Tx2RF-En, Tx1RF-En enable
    MFRC500_WrReg( RegInterruptEn, 0x7F );                          //  disable all interrupts
    MFRC500_WrReg( RegInterruptRq, 0x7F );                          //  reset interrupt request
    MFRC500_WrReg( RegCommand, PCD_IDLE );                          //  terminate probably running command
    FlushFIFO();                                                    //  flush FIFO buffer
    MFRC500_WrReg( RegInterruptEn, 0x88 );                          //  enable rx interrupt
    MFRC500_WrReg( RegFIFOData, PICC_REQSTD );											//	寻找未进入休眠的卡
    MFRC500_WrReg( RegCommand, PCD_TRANSCEIVE );                    //  send command，传送指令
}
/*****************************************************************
*    Function Name           :   MFRC500_FindCardEcho
*
*    Parameters              :
*
*    Description             :   等待寻卡命令执行结果
*
*    Returns                 :   0   成功
*                                -1  失败
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_FindCardEcho(void)
{
    uint8_t status=0;
    uint8_t count = 0;
    uint8_t secstatus = 0;
    uint8_t tmpA,tmpB;
    s8 tmpR = 0;
    SysTickDelay(10);
    //------------------------------------------------------------
    //  interrupt happen
    if( err == OS_ERR_NONE )
    {
        //  clear mf interrupt
        MFRC500_WrReg( RegInterruptEn, 0x7F );			 		//清除所有中断
        //  stop any cmd
        MFRC500_WrReg( RegCommand, PCD_IDLE );					//写入IDLE命令，让阅读器取消当前命令，处于空闲状态
        status = MFRC500_RdReg( RegErrorFlag ) & 0x17; 	//读取错误标志位，判断当前是否发生异常
        count = MFRC500_RdReg( RegFIFOLength );					//读取FIFO中的字节长度
        secstatus = MFRC500_RdReg( RegSecondaryStatus ) & 0x07;//读取最后接收的有效位数

        if( count == 2 && status == 0 && secstatus == 0 )
        {
            tmpA = MFRC500_RdReg( RegFIFOData );		//接收返回的卡类型
            tmpB = MFRC500_RdReg( RegFIFOData );		//接收返回的卡类型
            if( tmpA == 0x04 && tmpB == 0x00 )			//卡类型：0x0004 代表Mifare S50
            {
                tmpR = 0;
            }
        }
    }
    else                                           // time out or other error
    {
        tmpR = -1;
    }
    err=0;
    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_AnticollCmd
*
*    Parameters              :
*
*    Description             :   发出防冲突命令
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void MFRC500_AnticollCmd(void)
{
    MFRC500_WrReg( RegDecoderControl, 0x28 );                        //  ZeroAfterColl aktivieren
    MFRC500_ClrBitMask( RegControl, 0x08 );                          //  disable crypto 1 unit
    MFRC500_WrReg( RegChannelRedundancy, 0x03 );                     //  RxCRC and TxCRC disable, parity enable
    MFRC500_WrReg( RegInterruptEn, 0x7F );                           //  disable all interrupts
    MFRC500_WrReg( RegInterruptRq, 0x7F );                           //  reset interrupt request
    MFRC500_WrReg( RegCommand, PCD_IDLE );                           //  terminate probably running command
    FlushFIFO();
    MFRC500_WrReg( RegInterruptEn, 0x88 );                           //  enable rx interrupt
    MFRC500_WrReg( RegFIFOData, PICC_ANTICOLL1 );			//选择防冲突等级
    MFRC500_WrReg( RegFIFOData, 0x20 );
    MFRC500_WrReg( RegCommand, PCD_TRANSCEIVE );
}
/*****************************************************************
*    Function Name           :   MFRC500_AnticollEcho
*
*    Parameters              :
*
*    Description             :   等待防冲突命令完成，取得卡号
*
*    Returns                 :   0    成功
*                                -1   失败
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_AnticollEcho(u8* uidbuf)
{
    uint8_t status=0;
    uint8_t count = 0;
    uint8_t secstatus = 0;
    uint8_t i;
    s8 tmpR = 0;                                                    //  return value
    SysTickDelay(20);
    //============================================================
    //  interrupt happen
    if( err == OS_ERR_NONE )
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );
        MFRC500_WrReg( RegCommand, PCD_IDLE );
        status = MFRC500_RdReg( RegErrorFlag ) & 0x17;
        count = MFRC500_RdReg( RegFIFOLength );
        secstatus = MFRC500_RdReg( RegSecondaryStatus ) & 0x07;

        if( count == 5 && status == 0x00 && secstatus == 0x00 )  //开始接收UID，序列号
        {
            //  get the 4 uid and 1 check  ，读取UID,进行异或运算，进行校验
            for( i = 0; i < count; i ++ )
            {
                *(uidbuf+i) = MFRC500_RdReg( RegFIFOData );
            }
            //  check uid  expensive-or
            if(( (*(uidbuf+0)) ^ (*(uidbuf+1)) ^ (*(uidbuf+2)) ^ (*(uidbuf+3)) ) == (*(uidbuf+4)) )
                tmpR = 0;
            else  tmpR = -1;
        }
        else   tmpR = -1;
    }
    else    tmpR = -1;

    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_SelectCardCmd
*
*    Parameters              :   u8* uidbuf    卡ID
*
*    Description             :   发出选卡命令
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void MFRC500_SelectCardCmd(u8* uidbuf)
{
    uint8_t i;

    MFRC500_WrReg( RegChannelRedundancy, 0x0F );                    //  RxCRC,TxCRC,Parity enable
    MFRC500_ClrBitMask( RegControl, 0x08 );                         //  disable crypto 1 unit
    MFRC500_WrReg( RegInterruptEn, 0x7F );                          //  disable all interrupts
    MFRC500_WrReg( RegInterruptRq, 0x7F );                          //  reset interrupt request
    MFRC500_WrReg( RegCommand, PCD_IDLE );                          //  terminate probably running command
    FlushFIFO();
    MFRC500_WrReg( RegInterruptEn, 0x88 );                          //  enable rx interrupt
    MFRC500_WrReg( RegFIFOData, PICC_ANTICOLL1 );
    MFRC500_WrReg( RegFIFOData, 0x70 );															//发送NVB=70H
    for( i = 0; i < 5; i ++ )																				//发送40位的UID
    {
        MFRC500_WrReg( RegFIFOData, *(uidbuf+i) );
    }
    MFRC500_WrReg( RegCommand, PCD_TRANSCEIVE );
}
/*****************************************************************
*    Function Name           :   MFRC500_SelectCardEcho
*
*    Parameters              :
*
*    Description             :   等待选卡命令执行完毕
*
*    Returns                 :   0   成功
*                                -1  失败
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_SelectCardEcho(void)
{
    uint8_t status=0;
    uint8_t count = 0;
    uint8_t secstatus = 0;
    s8 tmpR = 0;
    SysTickDelay(20);
    //============================================================
    //  interrupt happen
    if( err == OS_ERR_NONE )
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );
        MFRC500_WrReg( RegCommand, PCD_IDLE );
        status = MFRC500_RdReg( RegErrorFlag ) & 0x17;
        count = MFRC500_RdReg( RegFIFOLength );
        secstatus = MFRC500_RdReg( RegSecondaryStatus ) & 0x07;

        if( count == 1 && status == 0x00 && secstatus == 0x00 )
        {
            tmpR = 0;
        }
        else
        {
            tmpR = -1;
        }
    }
    else
    {
        tmpR = -1;
    }

    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_LoadKeyCmd
*
*    Parameters              :   u8* keybuf   密钥
*
*    Description             :   装载密钥
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void MFRC500_LoadKeyCmd(u8* keybuf)
{
    uint8_t i;

    MFRC500_WrReg( RegInterruptEn, 0x7F );                           // disable all interrupts
    MFRC500_WrReg( RegInterruptRq, 0x7F );                           // reset interrupt request
    MFRC500_WrReg( RegCommand, PCD_IDLE );                           // terminate probably running command
    FlushFIFO();
    MFRC500_WrReg( RegInterruptEn, 0x84 );                           // enable idle interrupt

    MFRC500_PwdConvert( keybuf );                                    //  convert the key into a constant format
    for( i = 0; i < KEY_LENGTH; i ++ )
    {
        MFRC500_WrReg( RegFIFOData, *(keybuf+i) );                   //  write into the fifo
    }
    MFRC500_WrReg( RegCommand, PCD_LOADKEY );
}
/*****************************************************************
*    Function Name           :   MFRC500_LoadKeyEcho
*
*    Parameters              :
*
*    Description             :   等待装载命令执行完毕
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_LoadKeyEcho(void)
{
    uint8_t status=0;
    uint8_t secstatus = 0;
    s8 tmpR = 0;
    SysTickDelay(20);
    //============================================================
    //  interrupt happen
    if( err == OS_ERR_NONE )
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );
        MFRC500_WrReg( RegCommand, PCD_IDLE );
        status = MFRC500_RdReg( RegErrorFlag ) & 0x40;
        secstatus = MFRC500_RdReg( RegSecondaryStatus ) & 0x07;
        if( status == 0x00 && secstatus == 0x00 )
        {
            tmpR = 0;
        }
        else
        {
            tmpR = -1;
        }
    }
    else
    {
        tmpR = -1;
    }

    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_AuthenticCmd
*
*    Parameters              :   u8 mfblock
*                                u8* uidbuf
*    Description             :   发布授权命令
*
*    Returns                 :   0    成功
*                                -1   失败
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_AuthenticCmd(u8 mfblock,u8* uidbuf)
{
    uint8_t status=0;
    uint8_t secstatus = 0;
    uint8_t i;
    s8 tmpR = 0;

    MFRC500_WrReg( RegInterruptEn, 0x7F );                          //  disable all interrupts
    MFRC500_WrReg( RegInterruptRq, 0x7F );                          //  reset interrupt request
    MFRC500_WrReg( RegCommand, PCD_IDLE );                          //  terminate probably running command
    FlushFIFO();
    MFRC500_WrReg( RegInterruptEn, 0x84 );                          //  enable idle interrupt
    MFRC500_WrReg( RegFIFOData, PICC_AUTHENT1A );										//执行第一轮卡认证，选择认证密钥A

    MFRC500_WrReg( RegFIFOData, mfblock );													//选择要认证的Mifare块

    for( i = 0; i < UID_LENGHT; i ++ )															//装入密钥A到FIFO中
    {
        MFRC500_WrReg( RegFIFOData, *(uidbuf+i) );
    }

    MFRC500_WrReg( RegCommand, PCD_AUTHENT1 );											//执行第二轮卡认证
    SysTickDelay(20);
    //------------------------------------------------------------
    //  interrupt happen
    if( err == OS_ERR_NONE )
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );
        MFRC500_WrReg( RegCommand, PCD_IDLE );
        status = MFRC500_RdReg( RegErrorFlag ) & 0x17;
        secstatus = MFRC500_RdReg( RegSecondaryStatus ) & 0x07;
    }
    else
    {
        return -1;
    }

    if(  status || secstatus )
    {   //  error
        tmpR = -1;
    }
    else
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );                     //  disable all interrupts
        MFRC500_WrReg( RegInterruptRq, 0x7F );                     //  reset interrupt request
        MFRC500_WrReg( RegCommand, PCD_IDLE );                     //  terminate probably running command
        FlushFIFO();
        MFRC500_WrReg( RegInterruptEn, 0x84 );                     //  enable Idle interrupt
        MFRC500_WrReg( RegCommand, PCD_AUTHENT2 );									//执行第三轮的卡认证

        tmpR = 0;
    }
    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_AuthenticEcho
*
*    Parameters              :
*
*    Description             :   等待授执行完毕
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_AuthenticEcho(void)
{
    uint8_t status=0;
    uint8_t tmp;
    s8 tmpR = 0;
    SysTickDelay(20);
    //============================================================
    //  interrupt happen
    if( err == OS_ERR_NONE )
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );
        MFRC500_WrReg( RegCommand, PCD_IDLE );
        status = MFRC500_RdReg( RegErrorFlag ) & 0x17;
        //  Crypto1 unit is switched on and all data communication with the card is encrypted
        tmp = MFRC500_RdReg( RegControl ) & 0x08;
        if( (status == 0x00) && tmp )
        {
            tmpR = 0;
        }
        else
        {
            tmpR = -1;
        }
    }
    else
    {
        tmpR = -1;
    }

    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_RdCardCmd
*
*    Parameters              :   u8 mfblock   块号
*
*    Description             :   发布读卡命令
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void MFRC500_RdCardCmd(u8 mfblock)
{
    MFRC500_WrReg( RegChannelRedundancy, 0x0F );                    // RxCRC, TxCRC, Parity enable
    MFRC500_WrReg( RegInterruptEn, 0x7F );                          // disable all interrupts
    MFRC500_WrReg( RegInterruptRq, 0x7F );                          // reset interrupt request
    MFRC500_WrReg( RegCommand, PCD_IDLE );                          // terminate probably running command
    FlushFIFO();
    MFRC500_WrReg( RegInterruptEn, 0x84 );                          // enable idle interrupt
    MFRC500_WrReg( RegFIFOData, PICC_READ );												//发送读命令
    MFRC500_WrReg( RegFIFOData, mfblock );													//选择块
    MFRC500_WrReg( RegCommand, PCD_TRANSCEIVE );
}
/*****************************************************************
*    Function Name           :   MFRC500_RdCardEcho
*
*    Parameters              :   u8* databuf   数据缓冲区
*
*    Description             :   等待读卡执行结束
*
*    Returns                 :   0    成功
*                                -1   失败
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_RdCardEcho(u8* databuf)
{
    uint8_t status=0;
    uint8_t count = 0;
    uint8_t secstatus = 0;
    uint8_t i;
    s8 tmpR = 0;
    SysTickDelay(20);
    //============================================================
    //  interrupt happen
    if( err == OS_ERR_NONE )
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );
        MFRC500_WrReg( RegCommand, PCD_IDLE );
        status = MFRC500_RdReg( RegErrorFlag ) & 0x17;
        secstatus = MFRC500_RdReg( RegSecondaryStatus ) & 0x07;
        count = MFRC500_RdReg( RegFIFOLength );
        if( status == 0 && secstatus == 0 && count == 16 )
        {
            for( i = 0; i<16; i++ )
            {
                databuf[i] = 0;
            }
            for( i = 0; i < count; i ++ )
            {
                databuf[i] = MFRC500_RdReg( RegFIFOData );	//开始接收16字节数据
            }
            //  when finish reading card, then halt the card
            //  or you can not
            tmpR = 0;
        }
        else
        {
            tmpR = -1;
        }
    }
    else
    {
        tmpR = -1;
    }

    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_WrCardCmd
*
*    Parameters              :   u8 mfblock    块号
*                                u8* databuf   数据  16个字节
*    Description             :   发出写卡命令
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_WrCardCmd(u8 mfblock,u8* databuf)
{
    uint8_t status=0;
    uint8_t count = 0;
    uint8_t secstatus = 0;
    u8 i=0;
    s8 tmpR = 0;

    MFRC500_WrReg( RegInterruptEn, 0x7F );                          // disable all interrupts
    MFRC500_WrReg( RegInterruptRq, 0x7F );                          // reset interrupt request
    MFRC500_WrReg( RegCommand, PCD_IDLE );                          // terminate probably running command
    FlushFIFO();
    MFRC500_WrReg( RegInterruptEn, 0x88 );                          // enable rxirq interrupt
    MFRC500_WrReg( RegFIFOData, PICC_WRITE );												//发送写命令
    MFRC500_WrReg( RegFIFOData, mfblock );													//选择块
    MFRC500_WrReg( RegCommand, PCD_TRANSCEIVE );
    SysTickDelay(20);
    //  interrupt happen
    if( err == OS_ERR_NONE )
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );
        MFRC500_WrReg( RegInterruptRq, 0x7F );
        MFRC500_WrReg( RegCommand, PCD_IDLE );
        status = MFRC500_RdReg( RegErrorFlag ) & 0x17;
        secstatus = MFRC500_RdReg( RegSecondaryStatus ) & 0x07;
        count = MFRC500_RdReg( RegFIFOLength );
        if( secstatus == 0x04 && status == 0 && count == 1 )
        {
            if(( MFRC500_RdReg( RegFIFOData ) & 0x0F ) == 0x0A )
            {
                tmpR = 0;
            }
            else
            {
                return -1;
            }
        }
    }
    else
    {
        return -1;
    }

    MFRC500_WrReg( RegInterruptEn, 0x7F );                          // disable all interrupts
    MFRC500_WrReg( RegInterruptRq, 0x7F );                          // reset interrupt request
    MFRC500_WrReg( RegCommand, PCD_IDLE );                          // terminate probably running command
    FlushFIFO();
    MFRC500_WrReg( RegInterruptEn, 0x88 );                          // enable rxirq interrupt
    for( i=0; i<16; i++ )																							//将16字节的数据装入FIFO中
    {
        MFRC500_WrReg( RegFIFOData, *(databuf+i));
    }
    MFRC500_WrReg( RegCommand, PCD_TRANSCEIVE );

    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_WrCardEcho
*
*    Parameters              :
*
*    Description             :   等待写命题执行完毕
*
*    Returns                 :   0    成功
*                                -1   失败
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_WrCardEcho(void)
{
    uint8_t status=0;
    uint8_t count = 0;
    uint8_t secstatus = 0;
    s8 tmpR = 0;
    SysTickDelay(20);
    //============================================================
    //  interrupt happen  */
    if( err == OS_ERR_NONE )
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );
        MFRC500_WrReg( RegCommand, PCD_IDLE );
        status = MFRC500_RdReg( RegErrorFlag ) & 0x17;
        secstatus = MFRC500_RdReg( RegSecondaryStatus ) & 0x07;
        count = MFRC500_RdReg( RegFIFOLength );
        if( secstatus == 0x04 && status == 0 && count == 1 )	//接收ack
        {
            if(( MFRC500_RdReg( RegFIFOData ) & 0x0F ) == 0x0A )
            {
                tmpR = 0;
            }
            else
            {
                //  enter the idle state
                tmpR = -1;
            }
        }
    }
    else
    {
        //  enter the idle state
        tmpR = -1;
    }

    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC500_HaltCardCmd
*
*    Parameters              :
*
*    Description             :   发出休眠命令
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static void MFRC500_HaltCardCmd(void)
{
    MFRC500_WrReg( RegChannelRedundancy, 0x0F );
    MFRC500_WrReg( RegInterruptEn, 0x7F );                          //  disable all interrupts
    MFRC500_WrReg( RegInterruptRq, 0x7F );                          //  reset interrupt request
    MFRC500_WrReg( RegCommand, PCD_IDLE );                          //  terminate probably running command
    FlushFIFO();
    MFRC500_WrReg( RegInterruptEn, 0x90 );                          //  enable txirq interrupt
    MFRC500_WrReg( RegFIFOData, PICC_HALT );
    MFRC500_WrReg( RegFIFOData, 0x00 );
    MFRC500_WrReg( RegCommand, PCD_TRANSCEIVE );
}
/*****************************************************************
*    Function Name           :   MFRC500_HaltCardEcho
*
*    Parameters              :
*
*    Description             :   等待停卡命令的执行完毕
*
*    Returns                 :   0     成功
*                                -1    失败
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
static s8 MFRC500_HaltCardEcho(void)
{
    s8 tmpR = 0;
    SysTickDelay(20);
    //============================================================
    //  interrupt happen
    if( err == OS_ERR_NONE )
    {
        MFRC500_WrReg( RegInterruptEn, 0x7F );
        MFRC500_WrReg( RegCommand, PCD_IDLE );
        tmpR = 0;
    }
    else
    {
        tmpR = -1;
    }

    return tmpR;
}
/*****************************************************************
*    Function Name           :   MFRC_AppReset
*
*    Parameters              :
*
*    Description             :   阅读器进行复位
*
*    Returns                 :
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
s8 MFRC_AppReset(void)
{
    if( MFRC500_Reset() == -1)
    {
        //  复位失败
        return MFRC_RESET_FAIL;
    }
    // configure Reader
    MFRC500_Config();
    return MFRC_OK;
}
/*****************************************************************
*    Function Name           :   MFRC_AppFindCard
*
*    Parameters              :
*
*    Description             :   寻卡
*
*    Returns                 :   MFRC_FINDCARD_FAIL   寻卡失败
*                                MFRC_OK              寻卡成功
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
s8 MFRC_AppFindCard(void)
{
    MFRC500_FindCardCmd();

    if( MFRC500_FindCardEcho() == -1 )
    {   //  there is no card in the read area
        return MFRC_FINDCARD_FAIL;
    }
    return MFRC_OK;
}
/*****************************************************************
*    Function Name           :   MFRC_AppSelectCard
*
*    Parameters              :
*
*    Description             :   用于在寻卡后,选择卡
*
*    Returns                 :   MFRC_GETUID_FAIL      在获取UID的时候失败
*                                MFRC_SELECTCARD_FAIL  在选卡的时候失败
*                                MFRC_OK               操作成功
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
s8 MFRC_AppSelectCard(u8* tmpUidBuf)
{
    MFRC500_AnticollCmd(); //进行防碰撞命令

    if(MFRC500_AnticollEcho(tmpUidBuf) == -1)//接收UID，并进行校验
    {
        return MFRC_GETUID_FAIL;
    }

    MFRC500_SelectCardCmd(tmpUidBuf);		 //如果没有发生碰撞，发送UID回去
    if( MFRC500_SelectCardEcho() == -1 ) //接收SAK应答
    {
        return MFRC_SELECTCARD_FAIL;
    }

    return MFRC_OK;
}
/*****************************************************************
*    Function Name           :   MFRC_AppASLABlock
*
*    Parameters              :   u8 block   块号
*                                u8* key    加密密匙
*    Description             :   授权后，对卡进行读写
*
*    Returns                 :   MFRC_GETUID_FAIL      获取UID失败
*                                MFRC_SELECTCARD_FAIL  选卡失败
*                                MFRC_LOADKEY_FAIL     转载KEY失败
*                                MFRC_AUTHENTIC_FAIL   授权失败
*                                MFRC_OK               授权成功
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
s8 MFRC_AppASLABlock(u8 block,u8* key)
{
    u8 i;

    u8 tmpkeyBuf[12]= { 0 };

    if( MFRC_AppSelectCard(tmpUidBuf) != MFRC_OK )  //进行防碰撞操作，然后进行选卡
    {
        return MFRC_SELECTCARD_FAIL;
    }
    //------------------------------------------------------------

    for( i=0; i<6; i++ )
    {
        tmpkeyBuf[i] = *(key+i);
    }
    MFRC500_LoadKeyCmd(tmpkeyBuf);
    if( MFRC500_LoadKeyEcho() == -1 )
    {
        return MFRC_LOADKEY_FAIL;
    }

    MFRC500_AuthenticCmd(block,tmpUidBuf);   //进行第三轮认证
    if( MFRC500_AuthenticEcho() == -1 )
    {

        return MFRC_AUTHENTIC_FAIL;
    }
    return MFRC_OK;
}

/*****************************************************************
*    Function Name           :   MFRC_AppWrBlock
*
*    Parameters              :   u8 block    块号
*                                u8* data    数据指针
*    Description             :
*
*    Returns                 :   MFRC_WRCARDCMD_FAIL
*
*    Global Variable         :
*    File Static Variable    :
*    Function Static Variable:
*----------------------------------------------------------------
*    Revision History
*    No.    Date        Revised by        Item        Description
*
*****************************************************************/
s8 MFRC_AppWrBlock(u8 block,u8* data)
{
    if(MFRC500_WrCardCmd(block,data) == -1) //发送写命令，并发送数据
    {
        return MFRC_WRCARDCMD_FAIL;
    }

    if( MFRC500_WrCardEcho() == -1 )  //并接收ACK应答
    {
        return MFRC_WRDATA_FAIL;
    }

    return MFRC_OK;
}
/*****************************************************************
*    Function Name           :   MFRC_AppRdBlock
*
*    Parameters              :   u8 block       块号
                                 u8* databuf    数据指针
*    Description             :
*
*    Returns                 :   MFRC_READBLOCK_FAIL 读取失败
*                                MFRC_OK             读取成功

*****************************************************************/
s8 MFRC_AppRdBlock(u8 block,u8* databuf)
{
    MFRC500_RdCardCmd(block);  							//发送读取命令
    if( MFRC500_RdCardEcho(databuf) == -1)  //读取16字节数据
    {
        return MFRC_READBLOCK_FAIL;
    }
    return MFRC_OK;
}
/*****************************************************************
*    Function Name           :   MFRC_AppHaltCard
*
*    Parameters              :
*
*    Description             :   在选卡之后使卡进入休眠状态,卡只有退出
*                                工作范围后,重新进入才可以再次刷卡
*
*    Returns                 :   MFRC_HALTCARD_FAIL   休眠失败
*                                MFRC_OK              休眠成功

*****************************************************************/
s8 MFRC_AppHaltCard(void)
{
    MFRC500_HaltCardCmd();
    if( MFRC500_HaltCardEcho() == -1 )
    {
        return MFRC_HALTCARD_FAIL;
    }

    return MFRC_OK;
}


/*****************************************************************
*    Function Name(函数名)   :   MFRC_AppReadId
*																 读取ID
*    Parameters(参数)        :
*
*    Description(描述)       :
*
*    Returns(返回值)         :
*
*****************************************************************/
void MFRC_AppReadId(u8 * pid)
{
    int i=0;
    for(; i<4; i++)
    {
        *(pid+i)=*(tmpUidBuf+i);
    }
}
