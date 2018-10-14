#include "led.h"
#include "fn.h"
#include "relay.h"
#include "key.h"
#include "lcd.h"
//#include "font.h"
#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "13_56M.h"

#define LED2 PGout(2)
#define K2 PGin(2)
#define K3 PGin(3)

u8 KEY[6]={0xff,0xff,0xff,0xff,0xff,0xff};
// Line 400*257
int main(void)
{


    TFT_Init();	    
    MFRC_Init();
    FN_Init();
    LED_Init();
    RELAY_Init();
    KEY_Init();
    
	   TFT_desk();
	
    while(1) {
//        TFT_DrawLine (95,100,350,100) ;
//        TFT_DrawLine (95,100,95,240) ;
//        TFT_DrawLine (350,100,350,240) ;
//        TFT_DrawLine (95,240,350,240) ;



        if(MFRC_AppFindCard()== MFRC_OK) {
					if(MFRC_AppASLABlock(9,KEY)==MFRC_OK)	{
						//判断密码，进行授权
					TFT_Show_ID();
					GPIO_SetBits(GPIOC,GPIO_Pin_8);
					Delay(1000000);
					GPIO_ResetBits(GPIOC,GPIO_Pin_8);
					Delay(1000000);
					}
        }
        else {
            TFT_ShowString(160,112,"                       ");
            TFT_ShowString(160,144,"                       ");
        }

        if(K2 == 0) {

            GPIO_SetBits(GPIOD,GPIO_Pin_11);

            TFT_DrawLine(1,1,200,1);
            TFT_DrawLine(1,2,400,2);

            TFT_ShowChinese(10,7,0);//韦

            Delay(1000000);

            GPIO_ResetBits(GPIOD,GPIO_Pin_11);
            Delay(1000000);
        }

        if(K3==0) {

            TFT_ShowString(160,112,"                       ");
            TFT_ShowString(160,144,"                       ");


        }
        /*
                GPIO_SetBits(GPIOC,GPIO_Pin_8);
                GPIO_SetBits(GPIOC,GPIO_Pin_9);
                GPIO_SetBits(GPIOD,GPIO_Pin_11);
                Delay(10000000);

                GPIO_ResetBits(GPIOC,GPIO_Pin_8);
                GPIO_ResetBits(GPIOC,GPIO_Pin_9);
                //GPIO_SetBits(GPIOC,GPIO_Pin_9);
                GPIO_ResetBits(GPIOD,GPIO_Pin_11);
                Delay(10000000);

                GPIO_SetBits(GPIOC,GPIO_Pin_8);
                GPIO_SetBits(GPIOC,GPIO_Pin_9);
                GPIO_SetBits(GPIOD,GPIO_Pin_13);
                Delay(10000000);

                GPIO_ResetBits(GPIOC,GPIO_Pin_8);
                GPIO_ResetBits(GPIOC,GPIO_Pin_9);
                GPIO_ResetBits(GPIOD,GPIO_Pin_13);
                Delay(10000000);

                GPIO_SetBits(GPIOC,GPIO_Pin_8);
                GPIO_SetBits(GPIOC,GPIO_Pin_9);
                GPIO_SetBits(GPIOD,GPIO_Pin_14);
                Delay(10000000);

                GPIO_ResetBits(GPIOC,GPIO_Pin_8);
                GPIO_ResetBits(GPIOC,GPIO_Pin_9);
                GPIO_ResetBits(GPIOD,GPIO_Pin_14);
                Delay(10000000);

                GPIO_SetBits(GPIOC,GPIO_Pin_8);
                GPIO_SetBits(GPIOC,GPIO_Pin_9);
                GPIO_SetBits(GPIOD,GPIO_Pin_15);
                Delay(10000000);

                GPIO_ResetBits(GPIOC,GPIO_Pin_8);
                GPIO_ResetBits(GPIOC,GPIO_Pin_9);
                GPIO_ResetBits(GPIOD,GPIO_Pin_15);
                Delay(10000000);
        */
    }

}
/*

while(1) {
        GPIO_SetBits(GPIOC,GPIO_Pin_8);
        GPIO_SetBits(GPIOC,GPIO_Pin_9);
        GPIO_SetBits(GPIOD,GPIO_Pin_11);
        Delay(10000000);

        GPIO_ResetBits(GPIOC,GPIO_Pin_8);
        GPIO_ResetBits(GPIOC,GPIO_Pin_9);
        //GPIO_SetBits(GPIOC,GPIO_Pin_9);
        GPIO_ResetBits(GPIOD,GPIO_Pin_11);
        Delay(10000000);

        GPIO_SetBits(GPIOC,GPIO_Pin_8);
        GPIO_SetBits(GPIOC,GPIO_Pin_9);
        GPIO_SetBits(GPIOD,GPIO_Pin_13);
        Delay(10000000);

        GPIO_ResetBits(GPIOC,GPIO_Pin_8);
        GPIO_ResetBits(GPIOC,GPIO_Pin_9);
        GPIO_ResetBits(GPIOD,GPIO_Pin_13);
        Delay(10000000);

        GPIO_SetBits(GPIOC,GPIO_Pin_8);
        GPIO_SetBits(GPIOC,GPIO_Pin_9);
        GPIO_SetBits(GPIOD,GPIO_Pin_14);
        Delay(10000000);

        GPIO_ResetBits(GPIOC,GPIO_Pin_8);
        GPIO_ResetBits(GPIOC,GPIO_Pin_9);
        GPIO_ResetBits(GPIOD,GPIO_Pin_14);
        Delay(10000000);

        GPIO_SetBits(GPIOC,GPIO_Pin_8);
        GPIO_SetBits(GPIOC,GPIO_Pin_9);
        GPIO_SetBits(GPIOD,GPIO_Pin_15);
        Delay(10000000);

        GPIO_ResetBits(GPIOC,GPIO_Pin_8);
        GPIO_ResetBits(GPIOC,GPIO_Pin_9);
        GPIO_ResetBits(GPIOD,GPIO_Pin_15);
        Delay(10000000);

    }

*/







/*


		GPIO_SetBits(GPIOC,GPIO_Pin_8);
		GPIO_SetBits(GPIOC,GPIO_Pin_9);
		GPIO_SetBits(GPIOD,GPIO_Pin_13);
		Delay(30000000);

		GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		GPIO_ResetBits(GPIOC,GPIO_Pin_9);
		GPIO_ResetBits(GPIOD,GPIO_Pin_13);
		Delay(30000000);

		GPIO_SetBits(GPIOC,GPIO_Pin_8);
		GPIO_SetBits(GPIOC,GPIO_Pin_9);
		GPIO_SetBits(GPIOD,GPIO_Pin_14);
		Delay(30000000);

		GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		GPIO_ResetBits(GPIOC,GPIO_Pin_9);
		GPIO_ResetBits(GPIOD,GPIO_Pin_14);

		Delay(30000000);
		GPIO_SetBits(GPIOC,GPIO_Pin_8);
		GPIO_SetBits(GPIOC,GPIO_Pin_9);
		GPIO_SetBits(GPIOD,GPIO_Pin_15);
		Delay(30000000);

		GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		GPIO_ResetBits(GPIOC,GPIO_Pin_9);
		GPIO_ResetBits(GPIOD,GPIO_Pin_15);
		Delay(30000000);
		}


FN_Init();
	LED_Init();


	while(1){
		GPIO_SetBits(GPIOC,GPIO_Pin_8);
		GPIO_SetBits(GPIOD,GPIO_Pin_11);
		Delay(5000000);

		GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_11);
		Delay(5000000);

		GPIO_SetBits(GPIOC,GPIO_Pin_8);
		GPIO_SetBits(GPIOD,GPIO_Pin_13);
		Delay(5000000);

		GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_13);
		Delay(5000000);

			GPIO_SetBits(GPIOC,GPIO_Pin_8);
		GPIO_SetBits(GPIOD,GPIO_Pin_14);
		Delay(5000000);

		GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_14);
		Delay(5000000);
				GPIO_SetBits(GPIOC,GPIO_Pin_8);
		GPIO_SetBits(GPIOD,GPIO_Pin_15);
		Delay(5000000);

		GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_15);
		Delay(5000000);

	}

#include "stm32f10x.h"
#include "delay.h"
#include "13_56M.h"                       //添加头文件
#include "lcd.h"
#include "stdio.h"

u8 KEY[6]={0xff,0xff,0xff,0xff,0xff,0xff};

int main(void)
{

	TFT_Init();															//初始化TFT
  MFRC_Init();                            //初始化RC500,中断，优先级等

	TFT_Desk();															//显示个性化桌面

			while(1)
			{

							if(MFRC_AppFindCard() == MFRC_OK)    	  	//寻卡
							{
									 if(MFRC_AppASLABlock(9,KEY)==MFRC_OK)	//判断密码，进行授权
									{

											TFT_Show_ID();											//授权成功，显示卡ID
										  Delay(1000);
											Clear_TFT();
									}
							}else
							{
							}
		  }
}

*/





