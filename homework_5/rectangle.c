#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int rectangle(double w, double h, double *P, double *S);

int main()
{
    double weight, height;
    double per, s;
    printf("Enter weight and height of rectangle:\n");
    while ((fscanf(stdin,"%lf %lf", &weight, &height)) != EOF)
    {
        if (rectangle(weight, height, &per, &s) == -1)
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

int rectangle(double w, double h, double *P, double *S)
{
    if(w <= 0 || h<=0){
        return -1;
    }else{
        *P = 2 * (w + h);
        *S = w * h;
    }

    return 0;
}