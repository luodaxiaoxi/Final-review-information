
 
#include <LPC2103.H>	 //引用头文件
#include "firmware.h"

/*********************************************************************************************************
  宏定义
*********************************************************************************************************/
volatile uint8 i ;

#define LED            (1ul << i)
#define LED_Init()	   IODIR |= LED 	//设置P0.0为输出
#define LED_ON()       IOSET |= LED	//设置P0.0输出高电平
#define LED_OFF()      IOCLR |= LED   //设置P0.0输出低电平
/*********************************************************************************************************
** Function name:       myDelay
** Descriptions:        软件延时
** input parameters:    无
** output parameters:   无
** Returned value:      无
*********************************************************************************************************/
void myDelay (INT32U ulTime)
{
    INT32U i;

    i = 0;
    while (ulTime--) {
        for (i = 0; i < 5000; i++);
    }
}

/*********************************************************************************************************
** Function name:       main
** Descriptions:        测试程序（基于LPC2103的Keil4仿真）
** input parameters:    无
** output parameters:   无
** Returned value:      无
*********************************************************************************************************/
int main()
{ 
	PINSEL0 =  PINSEL0 & 0xFFFFFF00;	 //设置P0.0为GPIO
 

	while(1){
		for(i=0;i<4;i++)
		{
			LED_Init();
		    LED_ON();
		    myDelay(50); 
			LED_OFF();
			myDelay(50);
		}
	}

//	return 0;
}
