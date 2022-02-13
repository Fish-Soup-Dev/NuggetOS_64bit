#include "beep.h"
#include "nug.h"

void play_sound(int nFreq)
{
    int Div;
    char tmp;

    Div = 1193180 / nFreq;
    outb(0x43, 0xb6);
    outb(0x42, (char)Div);
    outb(0x42, (char)Div >> 8);

    tmp = inb(0x61);
    if (tmp != (tmp | 3))
    {
        outb(0x61, tmp | 3);
    }
}

void stop_sound()
{
    char tmp = inb(0x61) & 0xFC;
    outb(0x61, tmp);
}

void beep()
{
    play_sound(1000);
    sleep(0x02FFFFF);
    stop_sound();
}