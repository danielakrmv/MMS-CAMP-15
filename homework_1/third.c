#include <stdio.h>
#include <math.h>
const double PI = 3.141593;

double volume(double r, double h){
    return(PI * pow(r, 2) * h);
}

int main(){
    double R, H;
    printf("Enter R in metres:\n");
    scanf("%lf", &R);
    printf("Enter H in metres:\n");
    scanf("%lf", &H);
    double v = volume(R, H);
    printf("Volume is: %.2lf\n", v);
    return 0;
}