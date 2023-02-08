#include "DIO_interface.h"
#include "Timer_Interfacte.h"
#include "LED.h"
f64 on;
f64 off;
int status;
f64 count=0;
void handle_timer_ISR()
{
	count++;
	if (status==1)
	{
		if(count==on)
		{
				DIO_ChannelFlip();
			status=0;
			count=0;
		}
	}
	else if(status==0)
	{
		if(count==off)
		{
			DIO_ChannelFlip();
			status=1;
			count=0;
		}
	}

  
}
int main(void)
{
	  on=5;
	  off=5;
	  status=0;
    DIO_ActivateClock();
    DIO_EnableDigital();
    DIO_ChannelConfiguration(OUTPUT,1);
    DIO_ChannelConfiguration(INPUT,2);
	  DIO_ChannelConfiguration(INPUT,3);
	 
	  LED_Blink();
   while (1)
   {
    register_Timer_cb(handle_timer_ISR);  
    
		if(DIO_ChannelRead(2)==HIGH)
		{
			on++;
			off--;
		}
		else if(DIO_ChannelRead(3)==HIGH)
		{
			off++;
			on--;
		}
   }
}

