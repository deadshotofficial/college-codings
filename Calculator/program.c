#include <stdio.h>

int main() {
    char operator;
    double num1, num2;
    int inputStatus;

    printf("Calculator Program\n");
    printf("===================\n");
    printf("Enter an operator (+, -, *, /): ");
    inputStatus = scanf(" %c", &operator); // Add a space before %c to consume trailing newline

    if (inputStatus != 1) {
        printf("Error! Invalid operator input.\n");
        return 1; // Exit with error code
    }

    printf("Enter two numbers: ");
    inputStatus = scanf("%lf %lf", &num1, &num2);

    if (inputStatus != 2) {
        printf("Error! Invalid number input.\n");
        return 1; // Exit with error code
    }

    switch (operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            else
                printf("Error! Division by zero is not allowed.\n");
            break;
        default:
            printf("Error! Operator '%c' is not valid.\n", operator);
            break;
    }

    printf("Thank you for using the calculator!\n");

    return 0;
}
