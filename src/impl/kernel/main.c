#include "nugget.h"

void kernel_main()
{
    enable_cursor(13, 15);

    clr_scr();
    sleep_init();

    print_s("\n\nPlease enter your name: ");

    int max_len = 50;
    char str[max_len];

    if (input_str(str, max_len))
    {
        print_s("\nYour name is: ");
        print_s(str);
    }
}