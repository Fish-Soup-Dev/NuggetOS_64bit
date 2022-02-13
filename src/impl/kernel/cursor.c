#include "cursor.h"

void enable_cursor(uint8 cursor_start, uint8 cursor_end)
{
    outb(FB_COMMAND_PORT, 0x0A);
    outb(FB_DATA_PORT, (inb(FB_DATA_PORT) & 0xC0) | cursor_start);

    outb(FB_COMMAND_PORT, 0x0B);
    outb(FB_DATA_PORT, (inb(FB_DATA_PORT) & 0xE0) | cursor_end);
}

void move_cursor(uint16 col, uint16 row)
{
    uint16 pos = col + row * NUM_COLS;
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, ((pos >> 8) & 0xFF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0xFF);
}