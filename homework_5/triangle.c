#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int triangle(double a, double b, double c, double *P, double *S);

int main()
{
    double a1, b1, c1;
    double per, s;
    printf("Enter a, b and c:\n");
    while ((fcanf(stdin, "%lf %lf %lf", &a1, &b1, &c1)) != EOF)
    {
        if (triangle(a1, b1, c1, &per, &s) == -1)
        {
            fprintf(stderr, "Your data is invalid. Please try again.\n");
        }
        else
        {
            fprintf(stdout, "Perimeter is: %.2lf,\nS is: %.2lf\n", per, s);
        }
    }
    return 0;
}

int triangle(double a, double b, double c, double *P, double *S)
{
    if (a < 0 || b < 0 || c < 0 || a + b < c || b + c < a || c + a < b)
    {
        return -1;
    }
    else
    {
        *P = (a + b + c);
        *S = sqrt((*P / 2) * ((*P / 2) - a) * ((*P / 2) - b) * ((*P / 2) - c));
    }
    return 0;
}