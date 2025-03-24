#include <stdio.h>

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))

int main() {
    int x;
    printf("Size of int: %zu bytes\n", my_sizeof(x));
    return 0;
}

#include <stdio.h>

struct MyStruct {
    char a;
    int b;
    double c;
};

#define STRUCT_SIZE(s) ((char *)(&s + 1) - (char *)(&s))

int main() {
    struct MyStruct s;
    printf("Size of struct: %zu bytes\n", STRUCT_SIZE(s));
    return 0;
}


#include<stdio.h>

struct student{
    int roll;
    char name[100];
    float marks;
};

int main(){

  struct student *ptr = 0;

  ptr++;
  printf("Size of the structure student:  %d",ptr);

  return 0;
}
