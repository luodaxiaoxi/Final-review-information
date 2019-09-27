

#ifndef _SPI_HC595_H
#define _SPI_HC595_H


#include <LPC2103.H>
#include "firmware.h"

#define HC595_nCS    (1<<9)		//��P0.7����
#define HC595_RCK    (1<<8)		//��P0.8����


extern void HC595_Init(void);
extern uint8 HC595_SendData(uint8 data);


#endif                                                                
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
