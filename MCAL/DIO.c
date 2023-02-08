#include "DIO_interface.h"
#include "DIO_private.h"
#include "Bit_math.h"


void DIO_ActivateClock()
{
   SET_BIT(DIO_RCGC2,5);    
}

void DIO_EnableDigital()
{ 
   SET_BIT(DIO_DIGEN_PF,1);
	SET_BIT(DIO_DIGEN_PF,2);
	SET_BIT(DIO_DIGEN_PF,3);
}


void DIO_ChannelConfiguration(DIO_DirectionType Direction, int pin)
{
	if(pin==1)
    if (Direction == INPUT)
    {
        CLEAR_BIT(DIO_DIR_PF,1);
    }
    else
    {
        SET_BIT(DIO_DIR_PF,1);
    }
		else if(pin==2)
		{
			if (Direction == INPUT)
    {
        CLEAR_BIT(DIO_DIR_PF,2);
    }
    else
    {
        SET_BIT(DIO_DIR_PF,2);
    }
	}
		else
		{
			if (Direction == INPUT)
    {
        CLEAR_BIT(DIO_DIR_PF,3);
    }
    else
    {
        SET_BIT(DIO_DIR_PF,3);
    }
	}
}

void DIO_ChannelWrite(DIO_LevelType Level)
{
	

    if (Level == HIGH)
    {
        SET_BIT(DIO_DATA_PF,1);
    }
    else
    {
        CLEAR_BIT(DIO_DATA_PF,1);
    }

}

void DIO_ChannelFlip()
{
	
    TOGGLE_BIT(DIO_DATA_PF,1);
}


DIO_LevelType DIO_ChannelRead(int pin)
{
	DIO_LevelType Result ;

	
if(pin==1)
{
  if (CHECK_BIT(DIO_DATA_PF,1) == 1)
  {
      Result = HIGH;
  }
  else
  {
      Result = LOW;
  }
}
 else if(pin==2)
 {
	   if (CHECK_BIT(DIO_DATA_PF,2) == 1)
  {
      Result = HIGH;
  }
  else
  {
      Result = LOW;
  }
 }
else
{

  if (CHECK_BIT(DIO_DATA_PF,3) == 1)
  {
      Result = HIGH;
  }
  else
  {
      Result = LOW;
  }
}
	return Result;
}	
	
