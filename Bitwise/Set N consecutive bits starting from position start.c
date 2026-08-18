uint32_t mask = ((1U << n) - 1) << start;
num |= mask;


uint32_t mask;

if (n == 32)
    mask = 0xFFFFFFFFU;
else
    mask = ((1U << n) - 1U) << start;

num |= mask;


====================================================
Usually this means: set N consecutive bits to 1, starting at a given bit position, without changing the other bits.

1. Create the mask

For n consecutive 1s starting at start:

uint32_t mask = ((1U << n) - 1) << start;

For example, set 4 bits starting at bit 8:

uint32_t mask = ((1U << 4) - 1) << 8;

Step by step:

1U << 4
= 0001 0000


(1U << 4) - 1
= 0000 1111


0000 1111 << 8
= 0000 0000 0000 0000 0000 1111 0000 0000
                                      ↑
                                  bits 8-11

So:

mask = 0x00000F00
2. Insert/set the 1s

Use OR:

num |= mask;

Complete example:

#include <stdio.h>
#include <stdint.h>


int main()
{
    uint32_t num = 0x12340000;


    int start = 8;
    int n = 4;


    uint32_t mask = ((1U << n) - 1) << start;


    num |= mask;


    printf("num = 0x%08X\n", num);


    return 0;
}

Result:

Before:
0x12340000


Mask:
0x00000F00


After:
0x12340F00
