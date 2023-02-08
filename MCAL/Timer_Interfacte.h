#ifndef TIMER_INTERFACE
#define TIMER_INTERFACE
#include "Std_Types.h"
typedef void(*cb_type)(void);
void Timer_Systick_Delay(f64 delay);
void register_Timer_cb(void(*ptr)(void));



#endif