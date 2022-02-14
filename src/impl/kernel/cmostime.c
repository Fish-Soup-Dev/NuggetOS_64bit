#include "cmostime.h"

#define CMOS_PORT    0x70
#define CMOS_RETURN  0x71

#define CMOS_STATA   0x0a
#define CMOS_STATB   0x0b
#define CMOS_UIP    (1 << 7)

#define SECS    0x00
#define MINS    0x02
#define HOURS   0x04
#define DAY     0x07
#define MONTH   0x08
#define YEAR    0x09

uint16 cmos_read(uint16 reg)
{
    outb(CMOS_PORT, reg);
    sleep(10);
    return inb(CMOS_RETURN);
}

void fill_rtcdate(struct rtcdate *r)
{
    r->second = cmos_read(SECS);
    r->minute = cmos_read(MINS);
    r->hour   = cmos_read(HOURS);
    r->day    = cmos_read(DAY);
    r->month  = cmos_read(MONTH);
    r->year   = cmos_read(YEAR);
}

void cmostime(struct rtcdate *r)
{
    struct rtcdate t1, t2;
    uint32 sb, bcd;

    sb = cmos_read(CMOS_STATB);
    bcd = (sb & (1 << 2)) == 0;

    for(;;)
    {
        fill_rtcdate(&t1);
        if (cmos_read(CMOS_STATA) & CMOS_UIP)
        {
            continue;
        }
        fill_rtcdate(&t2);
        if (memcmp(&t1, &t2, sizeof(t1)) == 0)
        {
            break;
        }
    }

    if (bcd)
    {
        #define CONV(x) (t1.x = ((t1.x >> 4) * 10) + (t1.x & 0xF))
            CONV(second);
            CONV(minute);
            CONV(hour  );
            CONV(day   );
            CONV(month );
            CONV(year  );
        #undef CONV
    }

    *r = t1;
    r->year += 2000;
}