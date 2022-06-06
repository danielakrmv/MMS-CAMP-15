#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int cylinder(double r, double h, double *V, double *S);

int main()
{
    double r1, h1;
    double vol, s;
    printf("Enter r, h:\n");
    while ((fscanf(stdin, "%lf %lf", &r1, &h1)) != EOF)
    {
        if (cylinder(r1, h1, &vol, &s) == -1)
        {
            fprintf(stderr, "Your data is invalid. Please try again.\n");
        }
        else
        {
            printf(stdout"V is: %.2lf,\nS is: %.2lf\n", vol, s);
        }
    }
    return 0;
}

int cylinder(double r, double h, double *V, double *S)
{
    if (r < 0 || h < 0)
    {
        return -1;
    }
    else
    {
        double B = 3.14 * pow(r, 2);
        *V = B * h;
        double S1 = (2 * 3.14 * (pow(r, 2))) + B;
        *S = (2 * 3.14 * r)*(r + h);
    }
    return 0;
}