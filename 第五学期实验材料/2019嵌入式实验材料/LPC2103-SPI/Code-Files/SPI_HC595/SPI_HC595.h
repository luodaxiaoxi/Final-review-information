

#ifndef _SPI_HC595_H
#define _SPI_HC595_H


#include <LPC2103.H>
#include "firmware.h"

#define HC595_nCS    (1<<9)		//与P0.7连接
#define HC595_RCK    (1<<8)		//与P0.8连接


extern void HC595_Init(void);
extern uint8 HC595_SendData(uint8 data);


#endif                                                                
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
