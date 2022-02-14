#pragma once
#include "nugget.h"

#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

void enable_cursor(uint8 cursor_start, uint8 cursor_end);
void move_cursor(uint16 col, uint16 row);