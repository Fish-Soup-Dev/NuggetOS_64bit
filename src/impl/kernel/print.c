#include "print.h"

struct Char
{
    uint8 character;
    uint8 color;
};

struct Char* buffer = (struct Char*) 0xb8000;
uint16 col = 0;
uint16 row = 0;
uint8 color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;
uint8 deadzone = 2;

void clr_row(uint16 row)
{
    struct Char empty = (struct Char)
    {
        character: ' ',
        color: color,
    };

    for (uint16 col = 0; col < NUM_COLS; col++)
    {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void clr_col()
{
    col--;

    struct Char empty = (struct Char)
    {
        character: ' ',
        color: color,
    };

    buffer[col + NUM_COLS * row] = empty;

    move_cursor(col, row);
}

// clear whole screen
void clr_scr() {
    for (uint16 i = 0; i < NUM_ROWS; i++)
    {
        clr_row(i);
    }
    row = 0;
    col = 0;
}

// shift to the next row
void print_nl()
{
    col = 0;

    if (row < NUM_ROWS - 1 - deadzone)
    {
        row++;
        return;
    }

    for (uint16 row = 1; row < NUM_ROWS - deadzone + 1; row++)
    {
        for (uint16 col = 0; col < NUM_COLS; col++)
        {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clr_row(NUM_ROWS - 1);
    move_cursor(col, row);
}

// add one char to the screen buffer
void print_c(uint8 chr)
{
    if (chr == '\n')
    {
        print_nl();
        return;
    }

    if (col > NUM_COLS)
    {
        print_nl();
    }
    
    buffer[col + NUM_COLS * row] = (struct Char)
    {
        character: (uint8) chr,
        color: color
    };

    col++;
    move_cursor(col, row);
}

void print_i(int32 num)
{
    uint8 buf[digit_count(num) + 1];
    print_s(itoa(num, buf, 10));
}

// just do the print_char but like alot
void print_s(uint8* str)
{
    for (uint32 i = 0; 1; i++)
    {
        uint8 chr = (uint8)str[i];

        if (chr == '\0')
        {
            return;
        }

        print_c(chr);
    }
}

// change color of text
void set_print_color(uint8 f, uint8 b)
{
    color = f + (b << 4);
}

void pprint_char(uint8 column, uint8 row, uint8 character, uint8 color, uint8 bg_color)
{
    uint8 packed_color = color | bg_color << 4;
    buffer[column + NUM_COLS * row] = (struct Char)
    {
        character: character,
        color: color,
    };
}

void pprint_str(uint8 column, uint8 row, uint8* str, uint8 color, uint8 bg_color)
{
    for (uint16 i = 0; 1; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        pprint_char(column + i, row, str[i], color, bg_color);
    }
}

void pprint_int(uint8 column, uint8 row, int32 num, uint8 color, uint8 bg_color)
{
    char str[digit_count(num) + 1];
    itoa(num, str, 10);
    pprint_str(column, row, str, color, bg_color);
}

void pprint_int_pad(uint8 column, uint8 row, int32 num, uint8 pad, uint8 color, uint8 bg_color)
{
    char str[pad + 1];
    for (uint8 i = 1; i < pad; ++i)
    {
        str[i] = ' ';
    }
    str[pad] = '\0';
    itoa(num, str, 10);
    pprint_str(column, row, str, color, bg_color);
}

void pprint_int_pad0(uint8 column, uint8 row, int32 num, uint8 pad, uint8 color, uint8 bg_color)
{
    char str[pad + 1];
    for (uint8 i = 0; i < pad; ++i)
    {
        str[i] = '0';
    }
    itoa(num, &(str[pad - digit_count(num)]), 10);
    pprint_str(column, row, str, color, bg_color);
}