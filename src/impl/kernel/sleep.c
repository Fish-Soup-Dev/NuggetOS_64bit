#include "sleep.h"

void sleep_init()
{
    outb(0x43, 0x14);
    outb(0x40, 255);
}

void sleep(uint32 nanoseconds)
{
    uint32 ticks = nanoseconds + nanoseconds / 5;
    uint32 ticks_passed = 0;
    uint8 old_counter = inb(0x40);
    while (ticks_passed < ticks)
    {
        asm volatile("pause");
        uint8 counter = inb(0x40);
        uint8 delta = old_counter - counter;
        ticks_passed += delta;
        old_counter = counter;
    }
    
}