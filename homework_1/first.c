#include <stdio.h>
#include <math.h>

int main(){
    double weight, hight;
    printf("Enter weight in kg:\n");
    scanf("%lf", &weight);
    printf("Enter hight in metres:\n");
    scanf("%lf", &hight);
    printf("BMI is: %.2lf\n", weight / pow(hight, 2));
    return 0;
}