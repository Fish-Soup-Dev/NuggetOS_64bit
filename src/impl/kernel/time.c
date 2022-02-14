#include "time.h"

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