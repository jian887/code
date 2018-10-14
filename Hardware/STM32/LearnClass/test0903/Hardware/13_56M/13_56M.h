/*******************************************************************
*
*    COPYRIGHT            :    深圳市讯方通信技术有限公司
*
*******************************************************************/
#ifndef __13_56M_H__
#define __13_56M_H__

#include "stm32f10x.h"
#include "13_56M.h"

/*******************************************************************
*    Macro Define Section 
*******************************************************************/
#define MFRC500_GPIOG    GPIOG
#define MFRC500_GPIOD    GPIOD

#define  MFRC500_CS_SET()        GPIO_SetBits(MFRC500_GPIOG,GPIO_Pin_12)
#define  MFRC500_CS_CLR()        GPIO_ResetBits(MFRC500_GPIOG,GPIO_Pin_12)
                                
#define  MFRC500_RD_SET()        GPIO_SetBits(MFRC500_GPIOG,GPIO_Pin_11)
#define  MFRC500_RD_CLR()        GPIO_ResetBits(MFRC500_GPIOG,GPIO_Pin_11)
                                
#define  MFRC500_WR_SET()        GPIO_SetBits(MFRC500_GPIOG,GPIO_Pin_8)
#define  MFRC500_WR_CLR()        GPIO_ResetBits(MFRC500_GPIOG,GPIO_Pin_8)
                                
#define  MFRC500_PD_SET()        GPIO_SetBits(MFRC500_GPIOG,GPIO_Pin_10)
#define  MFRC500_PD_CLR()        GPIO_ResetBits(MFRC500_GPIOG,GPIO_Pin_10)
                                
#define  MFRC500_ALE_SET()       GPIO_SetBits(MFRC500_GPIOG,GPIO_Pin_7)
#define  MFRC500_ALE_CLR()       GPIO_ResetBits(MFRC500_GPIOG,GPIO_Pin_7)


#define  MFRC500_ADX_SETDATA(x)  {GPIO_ResetBits(MFRC500_GPIOD,0x00FF<<3);GPIO_SetBits(MFRC500_GPIOD,(x&0x00FF)<<3);}


#define  MFRC500_ADX_GETDATA()   (GPIO_ReadInputData(MFRC500_GPIOD)&(0x00FF<<3))>>3




// Mifare卡通讯控制指令
#define PICC_REQSTD             0x26       // request idle
#define PICC_REQALL             0x52       // request all
#define PICC_ANTICOLL1          0x93       // anticollision level 1
#define PICC_ANTICOLL2          0x95       // anticollision level 2
#define PICC_ANTICOLL3          0x97       // anticollision level 3
#define PICC_AUTHENT1A          0x60       // authentication step 1
#define PICC_AUTHENT1B          0x61       // authentication step 2
#define PICC_READ               0x30       // read block
#define PICC_WRITE              0xA0       // write block
#define PICC_DECREMENT          0xC0       // decrement value
#define PICC_INCREMENT          0xC1       // increment value
#define PICC_RESTORE            0xC2       // restore command code
#define PICC_TRANSFER           0xB0       // transfer command code
#define PICC_HALT               0x50       // halt

// Mf500控制指令
#define PCD_IDLE                0x00       // 没有操作，取消当前命令或本位状态
#define PCD_WRITEE2             0x01       // 从FIFO中获得数据并且写到EEProm中
#define PCD_READE2              0x03       // 从EEProm中读取数据并且放入FIFO中
#define PCD_LOADCONFIG          0x07       // 从EEProm中读取数据并且初始化寄存器
#define PCD_LOADKEYE2           0x0B       // 从EEProm中读出主密钥并且放入主密钥缓冲区中
#define PCD_AUTHENT1            0x0C       // 用加密算法执行第一部分的卡认证，注意：主密钥自动从主密钥缓冲区中获取，意味着LoadKeyE2指令必须在卡验证之前先执行
#define PCD_CALCCRC             0x12       // 激活CRC处理，注意：CRC计算结果可以从CRCResultXXX寄存器中读取出来
#define PCD_AUTHENT2            0x14       // 用加密算法执行第二部分的卡认证
#define PCD_RECEIVE             0x16       // 激活接收电路。在接收器真正启动之前，需等待直到寄存器RcvWait配置通过，注意：可能从FIFO中读取数据尽管接收是活动的，因此有可能及时从FIFO中接收几个字节数据
#define PCD_LOADKEY             0x19       // 从FIFO中读取主密钥并且把他放到主密钥缓冲区中，注意：主密钥以一定的格式准备的，因此12字节装入6字节的主密钥中
#define PCD_TRANSMIT            0x1A       // 将数据从FIFO中传送的卡内，注意：当命令激活时如果FIFO中有数据，这个数据会被立即传送，有可能写数据到FIFO中尽管传送已经被激活，因此要尽可能及时写数据到FIFO中
#define PCD_TRANSCEIVE          0x1E       // 将数据从FIFO中传到卡中，之后自动激活接收器，在接收器真正开始之前，机器状态等待直到RcvWait寄存器配置通过，注意：这个命令和发送接收指令联合使用
#define PCD_RESETPHASE          0x3F       // 运行复位和初始化相位，注意：这个命令不能被软件激活，只能由上电或硬件复位激活

// Rc500寄存器定义
// Page0 命令和状态寄存器
#define RegPage                 0x00       // 选中寄存器页
#define RegCommand              0x01       // 启动和停止命令的执行
#define RegFIFOData             0x02       // 64字节FIFO缓冲区输入和输出
#define RegPrimaryStatus        0x03       // 接收器和发送器以及FIFO缓冲区状态标志
#define RegFIFOLength           0x04       // FIFO中缓冲的字节数
#define RegSecondaryStatus      0x05       // 不同的状态标志
#define RegInterruptEn          0x06       // 使能和禁止中断请求通过的控制位
#define RegInterruptRq          0x07       // 中断请求标志

// Page1 控制和状态寄存器
#define RegControl              0x09       // 不同的控制标志：例如定时器，节电
#define RegErrorFlag            0x0A       // 显示上次命令执行错误状态的错误标志
#define RegCollPos              0x0B       // RF接口检测到的第一个冲突位的位置
#define RegTimerValue           0x0C       // 定时器的实际值
#define RegCRCResultLSB         0x0D       // CRC协处理器寄存器的最低位
#define RegCRCResultMSB         0x0E       // CRC协处理器寄存器的最高位
#define RegBitFraming           0x0F       // 位方式帧的调节

// Page2 发送器和编码器控制
#define RegTxControl            0x11       // 天线驱动脚TX1和TX2的逻辑状态控制
#define RegCWConductance        0x12       // 选择天线驱动脚TX1和TX2的电导率
#define RegPreSet13             0x13       // 该值不会改变
#define RegPreSet14             0x14       // 该值不会改变
#define RegModWidth             0x15       // 选择调整脉冲的宽度
#define RegPreSet16             0x16       // 该值不会改变
#define RegPreSet17             0x17       // 该值不会改变

// Page3 接收器和解码控制
#define RegRxControl1           0x19       // 控制接收器状态
#define RegDecoderControl       0x1A       // 控制解码器状态
#define RegBitPhase             0x1B       // 选择发送器和接收器时钟之间的位相位
#define RegRxThreshold          0x1C       // 选择位解码器的阀值
#define RegPreSet1D             0x1D       // 该值不会改变
#define RegRxControl2           0x1E       // 控制解码器状态和定义接收器的输入源
#define RegClockQControl        0x1F       // 控制时钟产生用于90度相移的Q信道时钟

// Page4 时序和信道冗余
#define RegRxWait               0x21       // 选择发送后，接收器启动前的时间间隔
#define RegChannelRedundancy    0x22       // 选择RF信道上数据完整性检测的类型和模式
#define RegCRCPresetLSB         0x23       // CRC寄存器预设值的低字节
#define RegCRCPresetMSB         0x24       // CRC寄存器预设值的高字节
#define RegPreSet25             0x25       // 该值不会改变
#define RegMfOutSelect          0x26       // 选择输出到管脚MFOUT的内部信号
#define RegPreSet27             0x27       // 该值不会改变

// Page5 FIFO,定时器和IRQ脚配置
#define RegFIFOLevel            0x29       // 选择定义FIFO上溢和下溢警告界限
#define RegTimerClock           0x2A       // 选择定时器时钟的分频器
#define RegTimerControl         0x2B       // 选择定时器的起始和停止条件
#define RegTimerReload          0x2C       // 定义定时器的预装值
#define RegIrqPinConfig         0x2D       // 配置IRQ脚的输出状态
#define RegPreSet2E             0x2E       // 该值不会改变
#define RegPreSet2F             0x2F       // 该值不会改变

// Page6 RFU 保留将来使用
#define RegRFU31                0x31       // 保留将来使用
#define RegRFU32                0x32       // 保留将来使用
#define RegRFU33                0x33       // 保留将来使用
#define RegRFU34                0x34       // 保留将来使用
#define RegRFU35                0x35       // 保留将来使用
#define RegRFU36                0x36       // 保留将来使用
#define RegRFU37                0x37       // 保留将来使用

// Page7 测试控制
#define RegRFU39                0x39       // 保留将来使用
#define RegTestAnaSelect        0x3A       // 选择模拟测试模式
#define RegPreSet3B             0x3B       // 该值不会改变
#define RegPreSet3C             0x3C       // 该值不会改变
#define RegTestDigiSelect       0x3D       // 选择数字测试模式
#define RegRFU3E                0x3E       // 保留将来使用
#define RegRFU3F                0x3F       // 保留将来使用

// 定义宏操作
#define FlushFIFO()         MFRC500_SetBitMask( RegControl, 0x01 ) // 清空FIFO

/*  error code  */
#define MFRC_OK                0
#define MFRC_RESET_FAIL       -1
#define MFRC_FINDCARD_FAIL    -2
#define MFRC_GETUID_FAIL      -3
#define MFRC_SELECTCARD_FAIL  -4
#define MFRC_LOADKEY_FAIL     -5
#define MFRC_AUTHENTIC_FAIL   -6
#define MFRC_WRCARDCMD_FAIL   -7
#define MFRC_WRDATA_FAIL      -8
#define MFRC_READBLOCK_FAIL   -9
#define MFRC_HALTCARD_FAIL    -10


/*  block define  */
/*  sector 1  */
#define USER_ID_BLOCK           4
#define USER_CELLNUM_BLOCK      5
#define USER_VALUE_BLOCK        6
/*  sector 2  */
#define USER_DISCOUNT_BLOCK     8
#define USER_BACKUP_0_BLOCK     9
#define USER_BACKUP_1_BLOCK     10
/*  sector 3  */
#define USER_BACKUP_2_BLOCK     12
#define USER_BACKUP_3_BLOCK     13
#define USER_BACKUP_4_BLOCK     14
/*  sector 4  */
#define THING_ID_BLOCK          16
#define THING_PRICE_BLOCK       17
#define THING_BACKUP_0_BLOCK    18
/*  sector 5  */
#define THING_BACKUP_1_BLOCK    20
#define THING_BACKUP_2_BLOCK    21
#define THING_BACKUP_3_BLOCK    22
/*  sector 6  */
#define THING_BACKUP_4_BLOCK    24
#define THING_BACKUP_5_BLOCK    25
#define THING_BACKUP_6_BLOCK    26

#define UID_LENGHT           4
#define KEY_LENGTH           12
#define BLOCKDATA_LEN        16

/*******************************************************************
*    Prototype Declare Section
*******************************************************************/

void MFRC_Init(void);//初始化
s8 MFRC_AppFindCard(void);//寻卡
s8 MFRC_AppHaltCard(void);//进入休眠状态
void MFRC_AppReadId(u8 *pid);//读取卡ID
s8 MFRC_AppASLABlock(u8 block,u8* key);//获取读写权利
s8 MFRC_AppWrBlock(u8 block,u8* data); //写块
s8 MFRC_AppRdBlock(u8 block,u8* databuf);//读块
#endif

