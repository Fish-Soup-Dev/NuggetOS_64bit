#include "apps.h"

void moneygame()
{
    pprint_str(35, 24, "game mode", PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);

    sleep(500000);

     int max_len = 50;
    char str[max_len];

    int x = 0, y = 0, ans = 0;

    set_print_color(PRINT_COLOR_LIGHT_BLUE, PRINT_COLOR_BLACK);
    print_s("\n----------Money Simulator-----------");
    print_s("\ntype start to well you know start.");
    set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);

    print_s("\ngame>");

    while (1)
    {
        if (input_str(str, max_len, false))
        {
            if (ic_strcmp(str, "start") == 0)
            {
                set_print_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
                print_s("\nyou win 100 money!!!!!!");
                set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
            }
        }
        sleep(1000000);
        break;
    }
}