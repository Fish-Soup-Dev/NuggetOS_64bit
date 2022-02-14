#pragma once
#include "nugget.h"

uint32 digit_count(int num);

uint8* itoa(int32 value, uint8* buffer, uint16 base);
int32 atoi(uint8* str);
float atof(int8* str);

uint32 abs(int32 value);
float powf(float num, float exp);
int32 powi(int32 num, int32 exp);

int16 ic_strcmp(uint8* s1, uint8* s2);
int32 memcmp(const void *v1, const void *v2, int32 n);

void sleep(uint32 cycles_count);