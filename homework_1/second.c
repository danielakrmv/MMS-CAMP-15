#include <stdio.h>
#include <math.h>

int main(){
    double weight, height, new_BMI;
    printf("Enter weight in kg:\n");
    scanf("%lf", &weight);
    printf("Enter height in metres:\n");
    scanf("%lf", &height);
    new_BMI = 1.3 * (weight / pow(height, 2.5));
    printf("New BMI is: %.2lf\n", new_BMI);
    return 0;
}