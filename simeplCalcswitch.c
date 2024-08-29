#include <stdio.h>
#include <limits.h>

double simpleCalc(double num1, double num2, char op)
{
    double result;

    // switch-case
    switch (op) {
    case '+':

        // Addition
        return result = num1 + num2;
        break;
    case '-':

        // Subtraction
        return result = num1 - num2;
        break;
    case '*':

        // Multiplication
        return result = num1 * num2;
        break;
    case '/':

        // Division

        if (num2 != 0) {
            return result = num1 / num2;
        }
        else {
            printf("Error! Division by zero.\n");
            return INT_MIN;
        }
        break;
    default:
        printf("Error! Operator is not correct.\n");
        return INT_MIN;
    }
}

int main()
{
    char op;
    double num1, num2, result;

    // Read the operator
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);

    // Read the two numbers
    printf("Enter two operands: ");
    scanf(" %lf %lf", &num1, &num2);
    printf("num1: %lf , num2: %lf",  num1, num2);

    result = simpleCalc(num1, num2, op);

    // Print the result
    printf("Result: %.2lf\n", result);

    return 0;
}
