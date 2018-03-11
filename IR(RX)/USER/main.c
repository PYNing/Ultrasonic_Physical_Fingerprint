//#include "led.h"
#include "delay.h"
//#include "key.h"
#include "sys.h"
//#include "lcd.h"
//#include "usart.h"	 
#include "remote.h"
//ALIENTEK战舰STM32开发板实验27
//红外遥控 实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司 	 
 void My_GPIO_Init(void);
 int main(void)
 {	 
	u8 key;
//	u8 t=0;	
// 	u8 *str=0;

	delay_init();	    	 //延时函数初始化	  
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//	uart_init(9600);	 	//串口初始化为9600
 //	LED_Init();			     //LED端口初始化
//	LCD_Init();	
//	KEY_Init();	 	
	Remote_Init();			//红外接收初始化		 	
	My_GPIO_Init();
// 	POINT_COLOR=RED;//设置字体为红色 
/*
	 LCD_ShowString(60,50,200,16,16,"WarShip STM32");	
	LCD_ShowString(60,70,200,16,16,"REMOTE TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2012/9/12");

   	LCD_ShowString(60,130,200,16,16,"KEYVAL:");	
   	LCD_ShowString(60,150,200,16,16,"KEYCNT:");	
   	LCD_ShowString(60,170,200,16,16,"SYMBOL:");	    
*/ 														 	  		    							  
	while(1)
	{
		key=Remote_Scan();	
		if(key)
		{	 
	//		LCD_ShowNum(116,130,key,3,16);		//显示键值
	//		LCD_ShowNum(116,150,RmtCnt,3,16);	//显示按键次数		  
			switch(key)
			{
//				case 0:str="ERROR";break;			   
//				case 162:str="POWER";break;	    
//				case 98:str="UP";break;	    
//				case 2:str="PLAY";break;		 
//				case 226:str="ALIENTEK";break;		  
//				case 194:str="RIGHT";break;	   
//				case 34:str="LEFT";break;		  
//				case 224:str="VOL-";break;		  
//				case 168:str="DOWN";break;		   
//				case 144:str="VOL+";break;		    
//				case 104://str="1";
//					break;		  
//				case 152://str="2";					
//					break;	   
				case 122://str="3";
					GPIO_SetBits(GPIOA,GPIO_Pin_3);						 //左输出
					GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);	//左输出	
				  break;	    
				case 16://str="4";
					GPIO_ResetBits(GPIOA,GPIO_Pin_3);						 //右输出
					GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);	//右输出		
				  break;		    
//				case 24:str="5";break;		    
//				case 122:str="6";break;		  
//				case 16:str="7";break;			   					
//				case 56:str="8";break;	 
//				case 90:str="9";break;
//				case 66:str="0";break;
//				case 82:str="DELETE";break;		 
			}
		//	LCD_Fill(116,170,116+8*8,170+16,WHITE);	//清楚之前的显示
		//	LCD_ShowString(116,170,200,16,16,str);	//显示SYMBOL
		}
	}
}

//GPIO_Pin_0：信号继电器
//GPIO_Pin_1：地继电器
//GPIO_Pin_2：左灯
//GPIO_Pin_3：右灯
void My_GPIO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_SetBits(GPIOA,GPIO_Pin_3);						 //左输出
 GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);	//左输出
}

