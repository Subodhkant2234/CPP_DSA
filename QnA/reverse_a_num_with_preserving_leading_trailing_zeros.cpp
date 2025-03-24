// Online C compiler to run C program online
//001 -> 100
//100 -> 001
#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char number[100];

    printf("Enter an integer (with leading/trailing zeros): ");
    scanf("%s", number);  // Read input as a string

    reverseString(number);  // Reverse the string

    printf("Reversed number: %s\n", number);
    return 0;
}
