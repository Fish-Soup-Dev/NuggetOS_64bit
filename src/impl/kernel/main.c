#include "nugget.h"

void show_date_time();

void kernel_main()
{
    enable_cursor(13, 15);

    clr_scr();
    sleep_init();

    set_print_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);

    print_s("  _   _                        _      ___  ____  \n");
    print_s(" | \\ | |_   _  __ _  __ _  ___| |_   / _ \\/ ___| \n");
    print_s(" |  \\| | | | |/ _` |/ _` |/ _ \\ __| | | | \\___ \\ \n");
    print_s(" | |\\  | |_| | (_| | (_| |  __/ |_  | |_| |___) |\n");
    print_s(" |_| \\_|\\__,_|\\__, |\\__, |\\___|\\__|  \\___/|____/ \n");
    print_s("              |___/ |___/                        \n");

    set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);

    char vendor_str[13];
    CPUID_vendor_string(vendor_str);
    print_s("Detected CPU: ");
    print_s(vendor_str);

    print_s("\n>");

    int max_len = 50;
    char str[max_len];

    while (1)
    {
        if (input_str(str, max_len))
        {
            if (ic_strcmp(str, "clear") == 0)
            {
                clr_scr();
                print_s(">");
            }
            else
            {
                set_print_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
                print_s("\nerror not valid command: ");
                print_s(str);
                set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
                print_s("\n>");
            }
        }

        show_date_time();
        sleep(500000);
    }
}

void show_date_time()
{
    struct rtcdate r;
    cmostime(&r);
    pprint_int(0, 24, r.year, PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    pprint_char(4, 24, '-', PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    pprint_int_pad0(5, 24, r.month, 2, PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    pprint_char(7, 24, '-', PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    pprint_int_pad0(8, 24, r.day, 2, PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);

    pprint_int_pad0(11, 24, r.hour, 2, PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    pprint_char(13, 24, ':', PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    pprint_int_pad0(14, 24, r.minute, 2, PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    pprint_char(16, 24, ':', PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    pprint_int_pad0(17, 24, r.second, 2, PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
}