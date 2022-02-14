#include "nugget.h"
#include "apps.h"

void logo()
{
    set_print_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);

    print_s("  _   _                        _      ___  ____  \n");
    print_s(" | \\ | |_   _  __ _  __ _  ___| |_   / _ \\/ ___| \n");
    print_s(" |  \\| | | | |/ _` |/ _` |/ _ \\ __| | | | \\___ \\ \n");
    print_s(" | |\\  | |_| | (_| | (_| |  __/ |_  | |_| |___) |\n");
    print_s(" |_| \\_|\\__,_|\\__, |\\__, |\\___|\\__|  \\___/|____/ \n");
    print_s("              |___/ |___/                        \n");

    set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
}

void kernel_main()
{
    enable_cursor(13, 15);

    clr_scr();
    sleep_init();
    logo();

    char vendor_str[13];
    CPUID_vendor_string(vendor_str);
    print_s("Detected CPU: ");
    print_s(vendor_str);

    print_s("\ncomp>");

    pprint_str(35, 24, "comp mode", PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);

    int max_len = 50;
    char str[max_len];

    while (1)
    {
        if (input_str(str, max_len, true))
        {
            if (ic_strcmp(str, "clear") == 0)
            {
                clr_scr();
                print_s("comp>");
            }
            else if (ic_strcmp(str, "calc") == 0)
            {
                clr_scr();
                math();
            
                clr_scr();
                print_s("comp>");
            }
            else if (ic_strcmp(str, "money simulator") == 0)
            {
                clr_scr();
                moneygame();

                clr_scr();
                print_s("comp>");
            }
            else if (ic_strcmp(str, "help") == 0)
            {
                set_print_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
                print_s("\nclear: clears screen");
                print_s("\nclac: opens calculator mode");
                print_s("\nmoney simulator: opens money simulator game");
                set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
                print_s("\ncomp>");
            }
            else
            {
                set_print_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
                print_s("\nerror not valid command: ");
                print_s(str);
                set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
                print_s("\ncomp>");
            }
        }

        pprint_str(35, 24, "comp mode", PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);
        show_date_time();
        sleep(500000);
    }
}