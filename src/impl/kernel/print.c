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
}

// shift to the next row
void print_nl()
{
    col = 0;

    if (row < NUM_ROWS - 1)
    {
        row++;
        return;
    }

    for (uint16 row = 1; row < NUM_ROWS; row++)
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