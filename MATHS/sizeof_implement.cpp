#include <stdio.h>

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))

int main() {
    int x;
    printf("Size of int: %zu bytes\n", my_sizeof(x));
    return 0;
}
