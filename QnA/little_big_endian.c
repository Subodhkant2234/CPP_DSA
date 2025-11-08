#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t x = 0x1;  // Only LSB is set
    char *p = (char*)&x;

    if (*p == 0x1)
        printf("Little-endian\n");
    else
        printf("Big-endian\n");

    return 0;
}
