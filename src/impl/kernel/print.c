#include "print.h"
#include "nug.h"

// size of screen
const static unsigned int NUM_COLS = 80;
const static unsigned int NUM_ROWS = 25;

struct Char
{
    unsigned char character;
    unsigned char color;
};

struct Char* buffer = (struct Char*) 0xb8000;
unsigned int col = 0;
unsigned int row = 0;
unsigned char color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

// clear just one line
void clr_row(unsigned int row)
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
        clr_row(i);
    }
    row = 0;
    col = 0;
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

    for (unsigned int row = 1; row < NUM_ROWS; row++)
    {
        for (unsigned int col = 0; col < NUM_COLS; col++)
        {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clr_row(NUM_COLS - 1);
}

// add one char to the screen buffer
void print_c(char chr)
{
    if (chr == '\n')
    {
        print_nl();
        return;
    }

    if (col > NUM_COLS - 1)
    {
        print_nl();
    }

    buffer[col + NUM_COLS * row] = (struct Char)
    {
        character: (unsigned char) chr,
        color: color
    };

    col++;
}

void print_i(int num)
{
    char buf[33];
    print_s(itoa(num, buf, 10));
}

// just do the print_char but like alot
void print_s(char* str)
{
    for (unsigned int i = 0; 1; i++)
    {
        char chr = (unsigned char)str[i];

        if (chr == '\0')
        {
            return;
        }

        print_c(chr);
    }
}

// change color of text
void set_print_color(unsigned char f, unsigned char b)
{
    color = f + (b << 4);
}