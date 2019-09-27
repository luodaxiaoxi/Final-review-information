
 
#include <LPC2103.H>	 //����ͷ�ļ�
#include "firmware.h"

/*********************************************************************************************************
  �궨��
*********************************************************************************************************/
volatile uint8 i ;

#define LED            (1ul << i)
#define LED_Init()	   IODIR |= LED 	//����P0.0Ϊ���
#define LED_ON()       IOSET |= LED	//����P0.0����ߵ�ƽ
#define LED_OFF()      IOCLR |= LED   //����P0.0����͵�ƽ
/*********************************************************************************************************
** Function name:       myDelay
** Descriptions:        �����ʱ
** input parameters:    ��
** output parameters:   ��
** Returned value:      ��
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
** Descriptions:        ���Գ��򣨻���LPC2103��Keil4���棩
** input parameters:    ��
** output parameters:   ��
** Returned value:      ��
*********************************************************************************************************/
int main()
{ 
	PINSEL0 =  PINSEL0 & 0xFFFFFF00;	 //����P0.0ΪGPIO
 

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
