#pragma once
#include "nugget.h"

#define NUM_COLS 80
#define NUM_ROWS 25

enum {
    PRINT_COLOR_BLACK = 0,
	PRINT_COLOR_BLUE = 1,
	PRINT_COLOR_GREEN = 2,
	PRINT_COLOR_CYAN = 3,
	PRINT_COLOR_RED = 4,
	PRINT_COLOR_MAGENTA = 5,
	PRINT_COLOR_BROWN = 6,
	PRINT_COLOR_LIGHT_GRAY = 7,
	PRINT_COLOR_DARK_GRAY = 8,
	PRINT_COLOR_LIGHT_BLUE = 9,
	PRINT_COLOR_LIGHT_GREEN = 10,
	PRINT_COLOR_LIGHT_CYAN = 11,
	PRINT_COLOR_LIGHT_RED = 12,
	PRINT_COLOR_PINK = 13,
	PRINT_COLOR_YELLOW = 14,
	PRINT_COLOR_WHITE = 15
};

void clr_scr();
void clr_col();
void clr_row(uint16 row);
void print_c(uint8 chr);
void print_i(int32 num);
void print_s(uint8* str);
void print_nl();
void set_print_color(uint8 f, uint8 b);

void pprint_char(uint8 column, uint8 row, uint8 character, uint8 color, uint8 bg_color);
void pprint_str(uint8 column, uint8 row, uint8* str, uint8 color, uint8 bg_color);
void pprint_int(uint8 column, uint8 row, int32 num, uint8 color, uint8 bg_color);
void pprint_int_pad(uint8 column, uint8 row, int32 num, uint8 pad, uint8 color, uint8 bg_color);
void pprint_int_pad0(uint8 column, uint8 row, int32 num, uint8 pad, uint8 color, uint8 bg_color);