#include "print.h"
#include "cursor.h"
#include "types.h"

void kernel_main()
{
    enable_cursor(13, 15);

    clr_scr();

    for (uint32 i = 1; i < 51; i++)
    {
        print_i(i);
        print_c('\n');
    }
}