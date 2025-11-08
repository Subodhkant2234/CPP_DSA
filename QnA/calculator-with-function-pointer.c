#include <stdio.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2;
    char op;
    
    // Function pointer declaration
    double (*operation)(double, double);

    printf("Enter an expression (e.g., 3 + 4): ");
    scanf("%lf %c %lf", &num1, &op, &num2);

    // Assign function pointer based on operator
    switch(op) {
        case '+':
            operation = add;
            break;
        case '-':
            operation = subtract;
            break;
        case '*':
            operation = multiply;
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            operation = divide;
            break;
        default:
            printf("Error: Invalid operator!\n");
            return 1;
    }

    // Call the function via pointer
    double result = operation(num1, num2);
    printf("Result: %.2lf\n", result);

    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}
