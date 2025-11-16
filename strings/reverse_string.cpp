#include <stdio.h>
#include <string.h>
//without third variable
void reverse(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        str[left] ^= str[right];
        str[right] ^= str[left];
        str[left] ^= str[right];

        left++;
        right--;
    }
}
//normal 
void reverse(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    char temp;

    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

//using pointer only
void reverse(char *str) {
    char *end = str;
    char temp;

    while (*end)  
        end++;     
    end--;         

    while (str < end) {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

