#include "io.h"

char inb(short port)
{
    char ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
    return ret;
}

void outb(short port, char val)
{
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}