#include "apps.h"

void convert()
{
    pprint_str(35, 24, "conv mode", PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);

    sleep(500000);

    int max_len = 50;
    char str[max_len];

    int x = 0, y = 0, ans = 0;

    print_s("\nconv>");

    while (1)
    {
        if (input_str(str, max_len, true))
        {
            if (ic_strcmp(str, "clear") == 0)
            {
                clr_scr();
                print_s("conv>");
                sleep(500000);
            }
            else if (ic_strcmp(str, "conv") == 0)
            {
                sleep(500000);
                print_s("\nenter number:");
                input_str(str, max_len, true);
                int32 x = atoi(str);

                sleep(500000);
                print_s("\nenter base:");
                input_str(str, max_len, true);
                uint16 y = atoi(str);

                print_nl();

                uint8 buf[digit_count(x) + 1];
                print_nl();
                
                print_s(itoa(x, buf, y));

                print_nl();
                print_s("conv>");
            }
            else if (ic_strcmp(str, "help") == 0)
            {
                set_print_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
                print_s("\nconv: first number is just a number. second number is the base, 2, 10, 16 etc.");
                print_s("\nexit: exits converter");
                set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
                print_s("\nconv>");
            }
            else if (ic_strcmp(str, "exit") == 0)
            {
                break;
            }
            else
            {
                set_print_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
                print_s("\nerror not valid command: ");
                print_s(str);
                set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
                print_s("\nconv>");
            }
        }

        pprint_str(35, 24, "conv mode", PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);
        sleep(500000);
    }
}