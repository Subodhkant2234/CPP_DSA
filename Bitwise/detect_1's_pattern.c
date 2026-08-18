Detect consecutive 1s

For example, detect whether the bit stream contains three consecutive 1s:

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


bool has_three_consecutive_ones(uint32_t n)
{
    return (n & (n >> 1) & (n >> 2)) != 0;
}


int main()
{
    uint32_t n = 0b10111010;


    if (has_three_consecutive_ones(n))
        printf("Pattern 111 found\n");
    else
        printf("Pattern 111 not found\n");


    return 0;
}
How it works

Suppose:

n       = 10111010
n >> 1  = 01011101
n >> 2  = 00101110
          --------
AND     = 00001000

Since the result is non-zero, 111 exists.

The general formula is:

n & (n >> 1) & (n >> 2)

for detecting 3 consecutive 1s.

For 4 consecutive 1s:

n & (n >> 1) & (n >> 2) & (n >> 3)

For N consecutive 1s, you can use a loop.
