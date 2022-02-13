#pragma once

#include "io.h"
#include "types.h"

uint8* itoa(int32 value, uint8* buffer, uint16 base);
uint32 abs(int32 value);
void sleep(uint32 cycles_count);