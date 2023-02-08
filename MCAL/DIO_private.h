#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#include "Std_Types.h"


#define DIO_PORTF_BASE           (0x40025000)
#define DIO_RCGC2_BASE           (0x400FE000)

#define DIO_DATA_OFFSET                  (0X3FC)
#define DIO_DIR_OFFSET                   (0x400)
#define DIO_DIGEN_OFFSET                   (0x51C)
#define DIO_RCGC2_OFFSET                     (0x108)


#define DIO_DATA_PF       (*(u32*)(DIO_PORTF_BASE + DIO_DATA_OFFSET))
#define DIO_DIR_PF        (*(u32*)(DIO_PORTF_BASE + DIO_DIR_OFFSET))
#define DIO_DIGEN_PF        (*(u32*)(DIO_PORTF_BASE + DIO_DIGEN_OFFSET))

#define DIO_RCGC2               (*(u32*)(DIO_RCGC2_BASE + DIO_RCGC2_OFFSET))



typedef enum
{
	INPUT,
	OUTPUT
}DIO_DirectionType;

typedef enum
{
	LOW,
	HIGH
}DIO_LevelType;

#endif