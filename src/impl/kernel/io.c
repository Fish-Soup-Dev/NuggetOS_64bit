#include "io.h"

uint8 inb(uint16 port)
{
    uint8 ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
    return ret;
}

void outb(uint16 port, uint8 val)
{
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}