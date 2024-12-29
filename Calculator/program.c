#include <stdio.h>

// Function declarations
void printWelcomeMessage();
char getOperator();
int getNumbers(double *num1, double *num2);
void performCalculation(char operator, double num1, double num2);

int main() {
    char operator;
    double num1, num2;

    // Print welcome message
    printWelcomeMessage();

    // Get operator
    operator = getOperator();
    if (operator == '\0') {
        return 1; // Exit with error code
    }

    // Get numbers
    if (!getNumbers(&num1, &num2)) {
        return 1; // Exit with error code
    }

    // Perform calculation
    performCalculation(operator, num1, num2);

    printf("Thank you for using the calculator!\n");
    return 0;
}

// Function definitions
void printWelcomeMessage() {
    printf("Calculator Program\n");
    printf("===================\n");
}

char getOperator() {
    char operator;
    int inputStatus;
    printf("Enter an operator (+, -, *, /): ");
    inputStatus = scanf(" %c", &operator); // Add a space before %c to consume trailing newline

    if (inputStatus != 1) {
        printf("Error! Invalid operator input.\n");
        return '\0'; // Return null character to indicate error
    }

    return operator;
}

int getNumbers(double *num1, double *num2) {
    int inputStatus;
    printf("Enter two numbers: ");
    inputStatus = scanf("%lf %lf", num1, num2);

    if (inputStatus != 2) {
        printf("Error! Invalid number input.\n");
        return 0; // Return 0 to indicate error
    }

    return 1; // Return 1 to indicate success
}

void performCalculation(char operator, double num1, double num2) {
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
}
