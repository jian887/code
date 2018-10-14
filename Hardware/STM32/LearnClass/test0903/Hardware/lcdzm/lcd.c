/*******************************************************************
*    COPYRIGHT            :    深圳市讯方通信技术有限公司
*
*******************************************************************/
#include "lcd.h"
#include "font.h" 
#include <stdlib.h>

unsigned int  HDP=479;
unsigned int  HT=531;
unsigned int  HPS=43;
unsigned int  LPS=8;
unsigned char HPW=10;

unsigned int  VDP=271;
unsigned int  VT=288;
unsigned int  VPS=12;
unsigned int  FPS=4;
unsigned char VPW=10;

//画笔颜色
u16  POINT_COLOR=RED;//默认红色    
u16  BACK_COLOR=WHITE;//背景颜色.默认为白色
/*******************************************************************
*    File Static Variable Define Section
*******************************************************************/

/*******************************************************************
*    Function Define Section
*******************************************************************/
void LCD_Delay (uint32_t nCount)
{
	__IO uint16_t i;	 	
	for (i=0;i<nCount*100;i++);
}

/*****************************************************************
*    Function Name           :   LCD_GPIO_Config
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
void LCD_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
    
    /* clock enable  */
	RCC_APB2PeriphClockCmd(LCM_APB2_CLOCK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = LCM_DAT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	/*  推挽输出  */
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	/*  50M时钟速度  */
	GPIO_Init(LCM_DAT_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = LCM_RS_PIN;
	GPIO_Init(LCM_RS_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCM_RD_PIN;
	GPIO_Init(LCM_RD_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCM_WR_PIN;
	GPIO_Init(LCM_WR_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCM_CS_PIN;
	GPIO_Init(LCM_CS_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCM_RESET_PIN;
	GPIO_Init(LCM_RESET_PORT, &GPIO_InitStructure);
}

/*****************************************************************
*    Function Name           :   LCD_Write_Cmd
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
void LCD_Write_Cmd(u16 LCD_Reg)
{
	LCM_CS_CLR();
	LCM_RS_CLR();
	LCM_DAT_SET(LCD_Reg); 
	LCM_WR_CLR();
	LCM_WR_SET();
	LCM_CS_SET();
}
/*****************************************************************
*    Function Name           :   LCD_Write_Dat
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
void LCD_Write_Dat(u16 LCD_Dat)
{
	LCM_CS_CLR();
	LCM_RS_SET();
	LCM_DAT_SET(LCD_Dat);
	LCM_WR_CLR();
	LCM_WR_SET();
	LCM_CS_SET();
}
/*****************************************************************
*    Function Name           :   LCD_ReadDat
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
u16 LCD_ReadDat(void)
{
	u16 temp;

	LCM_DAT_PIN_IN();
	LCM_CS_CLR();
	LCM_RS_SET();
	LCM_RD_CLR();
	temp = LCM_DAT_GET();	//读取数据
	LCM_RD_SET();
	LCM_CS_SET();
	LCM_DAT_PIN_OUT();

	return temp;   
}

/*****************************************************************
*    Function Name           :   LCD_ReadCmd
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
u16 LCD_ReadCmd(void)
{
	u16 temp;

	LCM_DAT_PIN_IN();
	LCM_CS_CLR();
	LCM_RS_CLR();
	LCM_RD_CLR();
	temp = LCM_DAT_GET();	//读取数据
	LCM_RD_SET();
	LCM_CS_SET();
	LCM_DAT_PIN_OUT();

	return temp;   
}

/*****************************************************************
*    Function Name           :   LCD_WriteReg
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
void LCD_WriteReg(u16 LCD_Reg, u16 LCD_Dat)
{
	LCD_Write_Cmd(LCD_Reg);
	LCD_Write_Dat(LCD_Dat);
}
/*****************************************************************
*    Function Name           :   LCD_ReadReg
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
u16 LCD_ReadReg(u16 LCD_Reg)
{
	u16 temp;

	LCD_Write_Cmd(LCD_Reg);  //写入要读的寄存器号  
	temp = LCD_ReadDat();    //LCD_ReadCmd();

	return temp; 
}

/*****************************************************************
*    Function Name           :   TFT_CLEAR
*																 清屏
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
void TFT_CLEAR(u32 color)
{
  	unsigned int l=480,w;

	LCD_Write_Cmd(0x002a);	
	LCD_Write_Dat(0);	    
	LCD_Write_Dat(0);
	LCD_Write_Dat(HDP>>8);	    
	LCD_Write_Dat(HDP&0x00ff);
  LCD_Write_Cmd(0x002b);	
	LCD_Write_Dat(0);	    
	LCD_Write_Dat(0);
	LCD_Write_Dat(VDP>>8);	    
	LCD_Write_Dat(VDP&0x00ff);
	LCD_Write_Cmd(0x002c);
	while(l--)
	{
	  	for(w=0;w<272;w++)
		{
			LCD_Write_Dat(color);		
		}
	} 
} 

/*****************************************************************
*    Function Name           :   lcd_rst
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
void lcd_rst(void)
{
	LCM_RESET_CLR();
	LCD_Delay(5);					   
	LCM_RESET_SET();		 	 
	LCD_Delay(5);	
}


void TFT_DrawPoint(unsigned int x,unsigned int y,unsigned int fontcolor)
{
	LCD_Write_Cmd(0x002A);	
	LCD_Write_Dat(x>>8);	    
	LCD_Write_Dat(x&0x00ff);
	LCD_Write_Dat(HDP>>8);	    
	LCD_Write_Dat(HDP&0x00ff);
    LCD_Write_Cmd(0x002b);	
	LCD_Write_Dat(y>>8);	    
	LCD_Write_Dat(y&0x00ff);
	LCD_Write_Dat(VDP>>8);	    
	LCD_Write_Dat(VDP&0x00ff);
	LCD_Write_Cmd(0x002c);	
	
	LCD_Write_Dat(fontcolor); 
}  


void TFT_ShowChar(unsigned int x,unsigned int y,unsigned int num,unsigned int size,unsigned int mode)
{       
#define MAX_CHAR_POSX 472
#define MAX_CHAR_POSY 264 
    unsigned int temp;
    unsigned int pos,t;      
    if(x>MAX_CHAR_POSX||y>MAX_CHAR_POSY)return;
    //设定一个字符所占的大小 
    //开辟空间
  LCD_Write_Cmd(0x002A);	
	LCD_Write_Dat(x>>8);	    
	LCD_Write_Dat(x&0x00ff);
	LCD_Write_Dat(x+(size/2-1)>>8);	    
	LCD_Write_Dat(x+(size/2-1)&0x00ff);
  LCD_Write_Cmd(0x002b);	
	LCD_Write_Dat(y>>8);	    
	LCD_Write_Dat(y&0x00ff);
	LCD_Write_Dat((y+size-1)>>8);	    
	LCD_Write_Dat((y+size-1)&0x00ff);
	LCD_Write_Cmd(0x002c);

	num=num-' ';//得到偏移后的值
	if(!mode) //非叠加方式
	{
		for(pos=0;pos<size;pos++)
		{
			if(size==12)temp=asc2_1206[num][pos];//调用1206字体
			else temp=asc2_1608[num][pos];		 //调用1608字体
			for(t=0;t<size/2;t++)
		    {                 
		        if(temp&0x01)

		          TFT_DrawPoint(x+t,y+pos,POINT_COLOR);
				else 

				  TFT_DrawPoint(x+t,y+pos,BACK_COLOR);    
		        temp>>=1; 
		    }
		}	
	}else//叠加方式
	{
		for(pos=0;pos<size;pos++)
		{
			if(size==12)temp=asc2_1206[num][pos];//调用1206字体
			else temp=asc2_1608[num][pos];		 //调用1608字体
			for(t=0;t<size/2;t++)
		    {                 
		        if(temp&0x01)TFT_DrawPoint(x+t,y+pos,POINT_COLOR);//画一个点     
		        temp>>=1; 
		    }
		}
	}
} 


/**
  * @brief  show chinese to lcd.
  * @param  x: x坐标,列 
  *   This parameter can be (0~29):
	* @param  y: y坐标.行 
	*   This parameter can be (0~16)
	* @param  num: 数组号（参考“font.h”文件中的chinese_1616[40][16]数组）
  * @retval None
*/
void TFT_ShowChinese(unsigned int x,unsigned int y,unsigned int num)
{
	unsigned short temp;
    unsigned short pos,t; 
		x=x*16;
		y=y*16;

	for(pos=0;pos<16;pos++)
		{
			temp=chinese_1616[num][pos];		 //调用中文16*16字体
			for(t=0;t<16;t++)
		    {    				             	  
		        if(temp&0x8000)

		          TFT_DrawPoint(x+t,y+pos,POINT_COLOR);
				else 

				  TFT_DrawPoint(x+t,y+pos,BACK_COLOR);    
		        temp<<=1; 
		    }
		}	
}

/**
  * @brief  show string to lcd.
  * @param  x: x坐标,列 
  *   This parameter can be (0~472):
	* @param  y: y坐标.行 
	*   This parameter can be (0~257)
	* @param  p: 字符串指针
  * @retval None
*/
void TFT_ShowString(unsigned int x,unsigned int y,  char *p)
{         
    while(*p!='\0')
    {       
        if(x>MAX_CHAR_POSX){x=0;y+=16;}
        if(y>MAX_CHAR_POSY){y=x=0;TFT_CLEAR(WHITE);}
        TFT_ShowChar(x,y,*p,16,0);
        x+=8;
        p++;
    }  
}



/**
  * @brief  show line to lcd.
  * @param  x1: 起点坐标x 
  *   This parameter can be (0~472):
	* @param  y1: 起点坐标y  
	*   This parameter can be (0~257)
  * @param  x2: 终点坐标x 
  *   This parameter can be (0~472):
	* @param  y2: 终点坐标y  
	*   This parameter can be (0~257) 
  * @retval None
*/
void TFT_DrawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
  unsigned int x, y, t;
	if((x1==x2)&&(y1==y2))TFT_DrawPoint(x1, y1,POINT_COLOR);
	else if(abs(y2-y1)>abs(x2-x1))//斜率大于1 
	{
		if(y1>y2) 
		{
			t=y1;
			y1=y2;
			y2=t; 
			t=x1;
			x1=x2;
			x2=t; 
		}
		for(y=y1;y<y2;y++)//以y轴为基准 
		{
			x=(unsigned long)(y-y1)*(x2-x1)/(y2-y1)+x1;
			TFT_DrawPoint(x, y,POINT_COLOR);  
		}
	}
	else     //斜率小于等于1 
	{
		if(x1>x2)
		{
			t=y1;
			y1=y2;
			y2=t;
			t=x1;
			x1=x2;
			x2=t;
		}   
		for(x=x1;x<=x2;x++)//以x轴为基准 
		{
			y =(unsigned long)(x-x1)*(y2-y1)/(x2-x1)+y1;
			TFT_DrawPoint(x,y,POINT_COLOR); 
		}
	} 
}

void TFT_desk()
{
	 TFT_DrawLine (95,100,350,100) ;
        TFT_DrawLine (95,100,95,240) ;
        TFT_DrawLine (350,100,350,240) ;
        TFT_DrawLine (95,240,350,240) ;
}

void TFT_Show_ID(){
		char id[16];
	          u8 ID[16];
						MFRC_AppReadId(ID);
	 					if((ID[0]&0x0f)>9)
								id[0] = (ID[0]&0x0f)-10+97;
							else 
								id[0] = (ID[0]&0x0f)+48;
							if(((ID[0]>>4)&0x0f)>9)
								id[1] = ((ID[0]>>4)&0x0f)-10+97;
							else 
								id[1] = ((ID[0]>>4)&0x0f)+48;

							if((ID[1]&0x0f)>9)
								id[2] = (ID[1]&0x0f)-10+97;
							else 
								id[2] = (ID[1]&0x0f)+48;
							if(((ID[1]>>4)&0x0f)>9)
								id[3] = ((ID[1]>>4)&0x0f)-10+97;
							else 
								id[3] = ((ID[1]>>4)&0x0f)+48;

							if((ID[2]&0x0f)>9)
								id[4] = (ID[2]&0x0f)-10+97;
							else 
								id[4] = (ID[2]&0x0f)+48;
							if(((ID[2]>>4)&0x0f)>9)
								id[5] = ((ID[2]>>4)&0x0f)-10+97;
							else 
								id[5] = ((ID[2]>>4)&0x0f)+48;

							if((ID[3]&0x0f)>9)
								id[6] = (ID[3]&0x0f)-10+97;
							else 
								id[6] = (ID[3]&0x0f)+48;
							if(((ID[3]>>4)&0x0f)>9)
								id[7] = ((ID[3]>>4)&0x0f)-10+97;
							else 
								id[7] = ((ID[3]>>4)&0x0f)+48;
							
							
							
							TFT_ShowString(158,144,id);
}


/*****************************************************************
*    Function Name           :   LCD_Init
*																 LCD初始化
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
void TFT_Init(void)
{
	LCD_GPIO_Config();
	lcd_rst();

	LCD_Write_Cmd(0x00E2);			//PLL multiplier, set PLL clock to 120M
	LCD_Write_Dat(0x0023);	    //N=0x36 for 6.5M, 0x23 for 10M crystal
	LCD_Write_Dat(0x0002);
	LCD_Write_Dat(0x0004);

	LCD_Write_Cmd(0x00E0);  		// PLL enable
	LCD_Write_Dat(0x0001);
	LCD_Delay(1);
	LCD_Write_Cmd(0x00E0);
	LCD_Write_Dat(0x0003);
	LCD_Delay(5);

	LCD_ReadReg(0x00E4); 				//get pll status

	LCD_Write_Cmd(0x0001);  		// software reset
	LCD_Delay(5);
	LCD_Write_Cmd(0x00E6);			//PLL setting for PCLK, depends on resolution
	LCD_Write_Dat(0x0001);
	LCD_Write_Dat(0x0033);
	LCD_Write_Dat(0x0032);

	LCD_Write_Cmd(0x00B0);			//LCD SPECIFICATION
	LCD_Write_Dat(0x0018);
	LCD_Write_Dat(0x0000);
	LCD_Write_Dat((HDP>>8)&0X00FF);  //Set HDP
	LCD_Write_Dat(HDP&0X00FF);
	LCD_Write_Dat((VDP>>8)&0X00FF);  //Set VDP
	LCD_Write_Dat(VDP&0X00FF);
	LCD_Write_Dat(0x0000);

	LCD_Write_Cmd(0x00B4);					//HSYNC
	LCD_Write_Dat((HT>>8)&0X00FF);  //Set HT
	LCD_Write_Dat(HT&0X00FF);
	LCD_Write_Dat((HPS>>8)&0X00FF);  //Set HPS
	LCD_Write_Dat(HPS&0X00FF);
	LCD_Write_Dat(HPW);			  			 //Set HPW
	LCD_Write_Dat((LPS>>8)&0X00FF);  //Set HPS
	LCD_Write_Dat(LPS&0X00FF);
	LCD_Write_Dat(0x0000);

	LCD_Write_Cmd(0x00B6);					 //VSYNC
	LCD_Write_Dat((VT>>8)&0X00FF);   //Set VT
	LCD_Write_Dat(VT&0X00FF);
	LCD_Write_Dat((VPS>>8)&0X00FF);  //Set VPS
	LCD_Write_Dat(VPS&0X00FF);
	LCD_Write_Dat(VPW);			  			 //Set VPW
	LCD_Write_Dat((FPS>>8)&0X00FF);  //Set FPS
	LCD_Write_Dat(FPS&0X00FF);

	LCD_Write_Cmd(0x00F0);					 //pixel data interface
	LCD_Write_Dat(0x0003);

	LCD_Write_Cmd(0x0021);					 //进入图形颜色翻转模式

	LCD_Write_Cmd(0x00BC);					 //重要
	LCD_Write_Dat(0x0080);				   //对比度
	LCD_Write_Dat(0x0080);					 //亮度
	LCD_Write_Dat(0x0080);			  	 //饱和度值  
	LCD_Write_Dat(0x0001);				 	 //处理机允许

	LCD_Delay(5);
	TFT_CLEAR(0xf800);
	LCD_Write_Cmd(0x0029); 				//display on
	LCD_Write_Cmd(0x00BE); 				//set PWM for B/L
	LCD_Write_Dat(0x0006);
	LCD_Write_Dat(0x00ff);

	LCD_Write_Dat(0x0001);
	LCD_Write_Dat(0x00f0);
	LCD_Write_Dat(0x0000);
	LCD_Write_Dat(0x0000);
	
	TFT_CLEAR(WHITE);  
	POINT_COLOR=RED;  
}




