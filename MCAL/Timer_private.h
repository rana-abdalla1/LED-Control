#ifndef TIMER_PRIVATE
#define TIMER_PRIVATE

#define CORE_PERIPHERALS_BASE           (0xE000E000)
#define STCTRL_OFFSET                   (0x010)
#define STRELOAD_OFFSET                 (0x014)
#define STCURRENT_OFFSET                (0x018)

#define STCTRL_REG       (*(u32*)(CORE_PERIPHERALS_BASE + STCTRL_OFFSET))
#define STRELOAD_REG       (*(u32*)(CORE_PERIPHERALS_BASE + STRELOAD_OFFSET))
#define STCURRENT_REG       (*(u32*)(CORE_PERIPHERALS_BASE + STCURRENT_OFFSET))

#endif