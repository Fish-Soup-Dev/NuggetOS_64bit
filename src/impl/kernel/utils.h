#pragma once

#include "io.h"
#include "types.h"

uint32 digit_count(int num);
uint8* itoa(int32 value, uint8* buffer, uint16 base);
int32 atoi(uint8* str);
uint32 abs(int32 value);
int16 ic_strcmp(uint8* s1, uint8* s2);
void sleep(uint32 cycles_count);