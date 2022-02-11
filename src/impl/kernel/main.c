#include "print.h"

void kernel_main()
{
    clr_scr();
    set_print_color(PRINT_COLOR_PINK, PRINT_COLOR_BLACK);
    char buffer[33];
    
    int x = 0;
    int y = 1;
    int temp = x + y;

    print_i(x);
    print_c('\n');
    print_i(y);
    print_c('\n');

    for (int i = 0; i < 20; i++)
    {
        print_i(temp);
        print_c('\n');

        x = y;
        y = temp;
        temp = x + y;
    }
}