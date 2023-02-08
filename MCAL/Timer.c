#include "Timer_Interfacte.h"
#include "Timer_private.h"
#include "Bit_math.h"
#include "Std_Types.h"
#include <stdio.h>
cb_type CallBack_ptr =NULL;

void register_Timer_cb(void(*ptr)(void))
{
	if(ptr!= NULL)
	{
		CallBack_ptr=ptr;
	}
}
void SysTick_Handler()
{
	if(CallBack_ptr!=NULL)
		(*CallBack_ptr)();
}
void Timer_Systick_Delay(f64 delay)
{
	//configure STRCL
	SET_BIT(STCTRL_REG,2); //use system clock
  SET_BIT(STCTRL_REG,1); //enable interrupt
	SET_BIT(STCTRL_REG,0); 
	
  
	

	//load value into STRELOAD
	
	STRELOAD_REG=( delay*16*1000000-1);
	
	
	//clear STCURRENT
	STCURRENT_REG=0x0;
}