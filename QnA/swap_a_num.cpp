// C Program to Swap Two Numbers using a 
// Temporary Variable
#include <stdio.h>

int main() {
    int a = 5, b = 10, temp;

    // Swapping values of a and  b
    temp = a;
    a = b;
    b = temp;

    printf("a = %d, b = %d\n", a, b);
    return 0;
}


// C Program to Swap Two Numbers without Using 
// a Temporary Variable
#include <stdio.h>

int main() {
    int a = 5, b = 10;

    // Arithmetic operations to swap values
    a = a + b;
    b = a - b;
    a = a - b;

    printf("a = %d, b = %d\n", a, b);
    return 0;
}


// C Program to Swap Two Numbers using Bitwise
// XOR Operator
#include <stdio.h>

int main() {
    int a = 5, b = 10;

    // Apply XOR operations in the given order
    // to swap values
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("a = %d, b = %d\n", a, b);
    return 0;
}

