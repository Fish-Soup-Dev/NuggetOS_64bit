#include "nug.h"

uint32 abs(int32 value)
{
    if (value < 0)
    {
        value = value * -1;
        return value;
    }
    return value;
}

// Function to swap two numbers
void swap(uint8 *x, uint8 *y)
{
    uint8 t = *x; *x = *y; *y = t;
}
 
// Function to reverse `buffer[i…j]`
uint8* reverse(uint8 *buffer, uint32 i, uint32 j)
{
    while (i < j)
    {
        swap(&buffer[i++], &buffer[j--]);
    }
 
    return buffer;
}
 
// Iterative function to implement `itoa()` function in C
uint8* itoa(int32 value, uint8* buffer, uint16 base)
{
    // invalid input
    if (base < 2 || base > 32)
    {
        return buffer;
    }
 
    // consider the absolute value of the number
    uint32 n = abs(value);
 
    uint32 i = 0;
    while (n)
    {
        int r = n % base;
 
        if (r >= 10)
        {
            buffer[i++] = 65 + (r - 10);
        }
        else
        {
            buffer[i++] = 48 + r;
        }
 
        n = n / base;
    }
 
    // if the number is 0
    if (i == 0)
    {
        buffer[i++] = '0';
    }
 
    // If the base is 10 and the value is negative, the resulting string
    // is preceded with a minus sign (-)
    // With any other base, value is always considered unsigned
    if (value < 0 && base == 10)
    {
        buffer[i++] = '-';
    }
 
    buffer[i] = '\0'; // null terminate string
 
    // reverse the string and return it
    return reverse(buffer, 0, i - 1);
}

void sleep(uint32 cycles_count)
{
    while (cycles_count-- > 0)
    {
        asm volatile("pause");
    }
}