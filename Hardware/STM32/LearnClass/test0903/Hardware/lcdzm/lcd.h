/*******************************************************************
*    Multi-Include-Prevent Section
*******************************************************************/
#ifndef __LCD_H__
#define __LCD_H__

#include "stm32f10x.h"
/*******************************************************************
*    Macro Define Section 
*******************************************************************/
//定义引脚
#define LCM_APB2_CLOCK 	RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOG|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOB

#define LCM_COMMON_CLOCK RCC_APB2Periph_GPIOE
#define LCM_COMMON_PORT  GPIOE

#define LCM_RS_CLOCK  RCC_APB2Periph_GPIOG 
#define LCM_RD_CLOCK  RCC_APB2Periph_GPIOG
#define LCM_WR_CLOCK  RCC_APB2Periph_GPIOD
#define LCM_CS_CLOCK  RCC_APB2Periph_GPIOG
#define LCM_RESET_CLOCK  RCC_APB2Periph_GPIOB
#define LCM_LED_CLOCK  RCC_APB2Periph_GPIOE
#define LCM_DAT_CLOCK  RCC_APB2Periph_GPIOE

#define LCM_RS_PORT  GPIOG
#define LCM_RD_PORT  GPIOG
#define LCM_WR_PORT  GPIOD
#define LCM_CS_PORT  GPIOG
#define LCM_RESET_PORT  GPIOB
#define LCM_LED_PORT  GPIOE
#define LCM_DAT_PORT  GPIOE

#define LCM_RS_PIN   GPIO_Pin_14
#define LCM_RD_PIN   GPIO_Pin_13
#define LCM_WR_PIN   GPIO_Pin_1
#define LCM_CS_PIN   GPIO_Pin_15
#define LCM_RESET_PIN   GPIO_Pin_5
//#define LCM_LED_PIN   GPIO_Pin_2
#define LCM_DAT_OFFSET 0
#define LCM_DAT_PIN   (0xffff<<LCM_DAT_OFFSET)
#define LCM_DAT_MASK   0xffff

#define LCM_RS_SET()  (LCM_RS_PORT->BSRR = LCM_RS_PIN)
#define LCM_RS_CLR()  (LCM_RS_PORT->BRR = LCM_RS_PIN)
#define LCM_RD_SET()  (LCM_RD_PORT->BSRR = LCM_RD_PIN)
#define LCM_RD_CLR()  (LCM_RD_PORT->BRR = LCM_RD_PIN)
#define LCM_WR_SET()  (LCM_WR_PORT->BSRR = LCM_WR_PIN)
#define LCM_WR_CLR()  (LCM_WR_PORT->BRR = LCM_WR_PIN)
#define LCM_CS_SET()  (LCM_CS_PORT->BSRR = LCM_CS_PIN)
#define LCM_CS_CLR()  (LCM_CS_PORT->BRR = LCM_CS_PIN)
#define LCM_RESET_SET()  (LCM_RESET_PORT->BSRR = LCM_RESET_PIN)
#define LCM_RESET_CLR()  (LCM_RESET_PORT->BRR = LCM_RESET_PIN)
#define LCM_LED_SET()  (LCM_LED_PORT->BSRR = LCM_LED_PIN)
#define LCM_LED_CLR()  (LCM_LED_PORT->BRR = LCM_LED_PIN)

#define LCM_DAT_PIN_IN()  do{LCM_DAT_PORT->CRH &= (u32)0x00000000; \
							 LCM_DAT_PORT->CRL &= (u32)0x00000000; \
							 LCM_DAT_PORT->CRH |= (u32)0x88888888; \
							 LCM_DAT_PORT->CRL |= (u32)0x88888888; \
							 LCM_DAT_PORT->ODR |= (u32)LCM_DAT_PIN;}while(0) /* 输入上拉 */

#define LCM_DAT_PIN_OUT()  do{LCM_DAT_PORT->CRH &= (u32)0x00000000;	\
					          LCM_DAT_PORT->CRL &= (u32)0x00000000;	\
							  LCM_DAT_PORT->CRH |= (u32)0x33333333;	\
							  LCM_DAT_PORT->CRL |= (u32)0x33333333;}while(0) /* 输出 */

#define LCM_DAT_SET(dat)  (LCM_DAT_PORT->ODR = dat)
#define LCM_DAT_GET()     ((uint16_t)LCM_DAT_PORT->IDR)

////TFTLCD里面颜色的定义		
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 	 0x001F  
#define BRED             0XF81F
#define GRED 			 			 0XFFE0
#define GBLUE			 			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 		 0XBC40 
#define BRRED 					 0XFC07 
#define GRAY  			 		 0X8430 
#define LGRAY            0XC618 

/*******************************************************************
*    Struct Define Section
*******************************************************************/

/*******************************************************************
*    Prototype Declare Section
*******************************************************************/
extern u16 POINT_COLOR;  
extern u16 BACK_COLOR;
extern u16 LcdShowFlag;


void TFT_Init(void);	    //LCD初始化
void TFT_DrawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);//LCD画线
void TFT_ShowString(unsigned int x,unsigned int y,  char *p);//LCD显示字符串
void TFT_ShowChinese(unsigned int x,unsigned int y,unsigned int num);//LCD显示中文


#endif
