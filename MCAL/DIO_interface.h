#ifndef DIO_INTERFACE
#define DIO_INTERFACE

#include "DIO_private.h"
DIO_LevelType DIO_ChannelRead(int pin);
void DIO_ChannelWrite(DIO_LevelType level);
void DIO_ChannelConfiguration(DIO_DirectionType dir,int pin);
void DIO_EnableDigital(void);
void DIO_ActivateClock(void);
void DIO_ChannelFlip(void);
#endif