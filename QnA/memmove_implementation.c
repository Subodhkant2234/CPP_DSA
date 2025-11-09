#include <stdio.h>
#include <stddef.h>

void *my_memmove(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;

    // If same buffer, nothing to do
    if (d == s || n == 0)
        return dest;

    if (d < s) {
        // Safe to copy forward
        for (size_t i = 0; i < n; i++)
            d[i] = s[i];
    } else {
        // Copy backward to prevent overwrite
        for (size_t i = n; i != 0; i--)
            d[i - 1] = s[i - 1];
    }

    return dest;
}

int main() {
    char data[20] = "Hello, World!";

    printf("Before memmove: %s\n", data);

    // Overlapping copy example
    my_memmove(data + 2, data, 10);

    printf("After memmove : %s\n", data);

    return 0;
}
