/*******************************************************************
*
*    COPYRIGHT            :    ������Ѷ��ͨ�ż������޹�˾
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




// Mifare��ͨѶ����ָ��
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

// Mf500����ָ��
#define PCD_IDLE                0x00       // û�в�����ȡ����ǰ�����λ״̬
#define PCD_WRITEE2             0x01       // ��FIFO�л�����ݲ���д��EEProm��
#define PCD_READE2              0x03       // ��EEProm�ж�ȡ���ݲ��ҷ���FIFO��
#define PCD_LOADCONFIG          0x07       // ��EEProm�ж�ȡ���ݲ��ҳ�ʼ���Ĵ���
#define PCD_LOADKEYE2           0x0B       // ��EEProm�ж�������Կ���ҷ�������Կ��������
#define PCD_AUTHENT1            0x0C       // �ü����㷨ִ�е�һ���ֵĿ���֤��ע�⣺����Կ�Զ�������Կ�������л�ȡ����ζ��LoadKeyE2ָ������ڿ���֤֮ǰ��ִ��
#define PCD_CALCCRC             0x12       // ����CRC����ע�⣺CRC���������Դ�CRCResultXXX�Ĵ����ж�ȡ����
#define PCD_AUTHENT2            0x14       // �ü����㷨ִ�еڶ����ֵĿ���֤
#define PCD_RECEIVE             0x16       // ������յ�·���ڽ�������������֮ǰ����ȴ�ֱ���Ĵ���RcvWait����ͨ����ע�⣺���ܴ�FIFO�ж�ȡ���ݾ��ܽ����ǻ�ģ�����п��ܼ�ʱ��FIFO�н��ռ����ֽ�����
#define PCD_LOADKEY             0x19       // ��FIFO�ж�ȡ����Կ���Ұ����ŵ�����Կ�������У�ע�⣺����Կ��һ���ĸ�ʽ׼���ģ����12�ֽ�װ��6�ֽڵ�����Կ��
#define PCD_TRANSMIT            0x1A       // �����ݴ�FIFO�д��͵Ŀ��ڣ�ע�⣺�������ʱ���FIFO�������ݣ�������ݻᱻ�������ͣ��п���д���ݵ�FIFO�о��ܴ����Ѿ���������Ҫ�����ܼ�ʱд���ݵ�FIFO��
#define PCD_TRANSCEIVE          0x1E       // �����ݴ�FIFO�д������У�֮���Զ�������������ڽ�����������ʼ֮ǰ������״̬�ȴ�ֱ��RcvWait�Ĵ�������ͨ����ע�⣺�������ͷ��ͽ���ָ������ʹ��
#define PCD_RESETPHASE          0x3F       // ���и�λ�ͳ�ʼ����λ��ע�⣺�������ܱ�������ֻ�����ϵ��Ӳ����λ����

// Rc500�Ĵ�������
// Page0 �����״̬�Ĵ���
#define RegPage                 0x00       // ѡ�мĴ���ҳ
#define RegCommand              0x01       // ������ֹͣ�����ִ��
#define RegFIFOData             0x02       // 64�ֽ�FIFO��������������
#define RegPrimaryStatus        0x03       // �������ͷ������Լ�FIFO������״̬��־
#define RegFIFOLength           0x04       // FIFO�л�����ֽ���
#define RegSecondaryStatus      0x05       // ��ͬ��״̬��־
#define RegInterruptEn          0x06       // ʹ�ܺͽ�ֹ�ж�����ͨ���Ŀ���λ
#define RegInterruptRq          0x07       // �ж������־

// Page1 ���ƺ�״̬�Ĵ���
#define RegControl              0x09       // ��ͬ�Ŀ��Ʊ�־�����綨ʱ�����ڵ�
#define RegErrorFlag            0x0A       // ��ʾ�ϴ�����ִ�д���״̬�Ĵ����־
#define RegCollPos              0x0B       // RF�ӿڼ�⵽�ĵ�һ����ͻλ��λ��
#define RegTimerValue           0x0C       // ��ʱ����ʵ��ֵ
#define RegCRCResultLSB         0x0D       // CRCЭ�������Ĵ��������λ
#define RegCRCResultMSB         0x0E       // CRCЭ�������Ĵ��������λ
#define RegBitFraming           0x0F       // λ��ʽ֡�ĵ���

// Page2 �������ͱ���������
#define RegTxControl            0x11       // ����������TX1��TX2���߼�״̬����
#define RegCWConductance        0x12       // ѡ������������TX1��TX2�ĵ絼��
#define RegPreSet13             0x13       // ��ֵ����ı�
#define RegPreSet14             0x14       // ��ֵ����ı�
#define RegModWidth             0x15       // ѡ���������Ŀ��
#define RegPreSet16             0x16       // ��ֵ����ı�
#define RegPreSet17             0x17       // ��ֵ����ı�

// Page3 �������ͽ������
#define RegRxControl1           0x19       // ���ƽ�����״̬
#define RegDecoderControl       0x1A       // ���ƽ�����״̬
#define RegBitPhase             0x1B       // ѡ�������ͽ�����ʱ��֮���λ��λ
#define RegRxThreshold          0x1C       // ѡ��λ�������ķ�ֵ
#define RegPreSet1D             0x1D       // ��ֵ����ı�
#define RegRxControl2           0x1E       // ���ƽ�����״̬�Ͷ��������������Դ
#define RegClockQControl        0x1F       // ����ʱ�Ӳ�������90�����Ƶ�Q�ŵ�ʱ��

// Page4 ʱ����ŵ�����
#define RegRxWait               0x21       // ѡ���ͺ󣬽���������ǰ��ʱ����
#define RegChannelRedundancy    0x22       // ѡ��RF�ŵ������������Լ������ͺ�ģʽ
#define RegCRCPresetLSB         0x23       // CRC�Ĵ���Ԥ��ֵ�ĵ��ֽ�
#define RegCRCPresetMSB         0x24       // CRC�Ĵ���Ԥ��ֵ�ĸ��ֽ�
#define RegPreSet25             0x25       // ��ֵ����ı�
#define RegMfOutSelect          0x26       // ѡ��������ܽ�MFOUT���ڲ��ź�
#define RegPreSet27             0x27       // ��ֵ����ı�

// Page5 FIFO,��ʱ����IRQ������
#define RegFIFOLevel            0x29       // ѡ����FIFO��������羯�����
#define RegTimerClock           0x2A       // ѡ��ʱ��ʱ�ӵķ�Ƶ��
#define RegTimerControl         0x2B       // ѡ��ʱ������ʼ��ֹͣ����
#define RegTimerReload          0x2C       // ���嶨ʱ����Ԥװֵ
#define RegIrqPinConfig         0x2D       // ����IRQ�ŵ����״̬
#define RegPreSet2E             0x2E       // ��ֵ����ı�
#define RegPreSet2F             0x2F       // ��ֵ����ı�

// Page6 RFU ��������ʹ��
#define RegRFU31                0x31       // ��������ʹ��
#define RegRFU32                0x32       // ��������ʹ��
#define RegRFU33                0x33       // ��������ʹ��
#define RegRFU34                0x34       // ��������ʹ��
#define RegRFU35                0x35       // ��������ʹ��
#define RegRFU36                0x36       // ��������ʹ��
#define RegRFU37                0x37       // ��������ʹ��

// Page7 ���Կ���
#define RegRFU39                0x39       // ��������ʹ��
#define RegTestAnaSelect        0x3A       // ѡ��ģ�����ģʽ
#define RegPreSet3B             0x3B       // ��ֵ����ı�
#define RegPreSet3C             0x3C       // ��ֵ����ı�
#define RegTestDigiSelect       0x3D       // ѡ�����ֲ���ģʽ
#define RegRFU3E                0x3E       // ��������ʹ��
#define RegRFU3F                0x3F       // ��������ʹ��

// ��������
#define FlushFIFO()         MFRC500_SetBitMask( RegControl, 0x01 ) // ���FIFO

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

void MFRC_Init(void);//��ʼ��
s8 MFRC_AppFindCard(void);//Ѱ��
s8 MFRC_AppHaltCard(void);//��������״̬
void MFRC_AppReadId(u8 *pid);//��ȡ��ID
s8 MFRC_AppASLABlock(u8 block,u8* key);//��ȡ��дȨ��
s8 MFRC_AppWrBlock(u8 block,u8* data); //д��
s8 MFRC_AppRdBlock(u8 block,u8* databuf);//����
#endif

