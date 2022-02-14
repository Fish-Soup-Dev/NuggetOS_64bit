#pragma once
#include "nugget.h"

struct rtcdate
{
    uint16 second;
    uint16 minute;
    uint16 hour;
    uint16 day;
    uint16 month;
    uint16 year;
};

void cmostime(struct rtcdate *r);