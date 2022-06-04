#include <stdio.h>
#include <math.h>

int main(){
    double R, L, H;
    printf("Enter R, L, H in metres:\n");
    scanf("%lf %lf %lf", &R, &L, &H);
    double volume = L * (pow(R, 2)*acos((R-H)/R) - ((R-H)*sqrt(2*R*H - pow(H, 2))));
    printf("Volume is: %.2lf\n", volume);
    return 0;
}