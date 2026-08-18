#include <stdint.h>

uint32_t byte_swap32(uint32_t num)
{
    return ((num & 0x000000FFU) << 24) |
           ((num & 0x0000FF00U) << 8)  |
           ((num & 0x00FF0000U) >> 8)  |
           ((num & 0xFF000000U) >> 24);
}
