#include "utils.h"

uint32 abs(int32 value)
{
    if (value < 0)
    {
        value = value * -1;
        return value;
    }
    return value;
}

uint32 digit_count(int num)
{
    if (num < 0)
    {
        return digit_count(-num) + 1;
    }
    if (num == 0)
    {
        return 1;
    }
    uint32 count = 0;
    while (num > 0)
    {
        count++;
        num = num / 10;
    }
    return count;
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

int32 atoi(uint8* str)
{
	int32 sign = 1, base = 0, i = 0;
	
	while (str[i] == ' ')
	{
		i++;
	}

	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i++] == '-');
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		if (base > 2147483647 / 10 || (base == 2147483647 / 10 && str[i] - '0' > 7))
		{
			if (sign == 1)
				return 2147483647;
			else
				return -2147483648;
		}
		base = 10 * base + (str[i++] - '0');
	}
	return base * sign;
}

int16 ic_strcmp(uint8* s1, uint8* s2)
{
    int16 i;
    for (i = 0; s1[i] && s2[i]; ++i)
    {
        /* If characters are same or inverting the
           6th bit makes them same */
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
           continue;
        else
           break;
    }
 
    /* Compare the last (or first mismatching in
       case of not same) characters */
    if (s1[i] == s2[i])
        return 0;
 
    // Set the 6th bit in both, then compare
    if ((s1[i] | 32) < (s2[i] | 32))
        return -1;
    return 1;
}