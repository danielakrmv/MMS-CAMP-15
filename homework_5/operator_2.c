#include <stdio.h>

int main()
{

    char op;
    double first, second;
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);
    printf("Enter operands: ");
    while ((scanf("%lf", &first, &second)) != EOF)
    {
        if (op = '+')
        {
            printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
        }
        else if (op = '-')
        {
            printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
        }
        else if (op = '*')
        {
            printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
        }
        else if (op = '/')
        {
            printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
        }
        // operator doesn't match any case constant
        else
        {
            printf("Error! operator is not correct");
        }
    }

    return 0;
}