#include "print.h"

#include <stddef.h>

// size of screen
const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char
{
    short character;
    short color;
};

struct Char* buffer = (struct Char*) 0xb8000;
unsigned int col = 0;
unsigned int row = 0;
short color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

// clear just one line
void clr_line(unsigned int row)
{
    struct Char empty = (struct Char)
    {
        character: ' ',
        color: color
    };

    for (unsigned int col = 0; col < NUM_COLS; col++)
    {
        buffer[col + NUM_COLS * row] = empty;
    }
}

// clear whole screen
void clr_scr()
{
    for (unsigned int i = 0; i < NUM_ROWS; i++)
    {
        clr_line(i);
    }
}

// shift the cursor to the new row
void print_nl()
{
    col = 0;

    if (row < NUM_ROWS - 1)
    {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++)
    {
        for (size_t col = 0; col < NUM_COLS; col++)
        {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clr_line(NUM_COLS - 1);
}

void print_char(char c)
{
    if (c == '\n')
    {
        print_nl();
        return;
    }
    if(col > NUM_COLS)
    {
        print_nl();
    }

    buffer[col + NUM_COLS * row] = (struct Char)
    {
        character: (short)c,
        color: color
    };

    col++;
}

void set_print_color(short f, short b)
{

}