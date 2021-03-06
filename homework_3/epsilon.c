#include <stdio.h>
#include <math.h>

#define EPS 0.001
int compare1(double a, double b);
int compare2(double a, double b);
int compare3(double, double, double);
int compare4(double , double);
int main(){
    
    double a = 100;
    double b = 0.0;
    double epsilon;
    int compOnePlus =0, compOneMinus=0,compTwoplus =0,compTwoMinus = 0,
    compThreePlus = 0, compThreeMinus = 0,compFourPlus = 0, compFourMinus =0;
    for (int i = 0; i < 1000; i++){
        b += 0.1;
    }
    int n = 1000;
    while (1) {
        printf("Enter epsilon: ");
        scanf("%f", &epsilon);
        while ( n > 0) {
            if(compare1(a,b)) {
                compOnePlus++;
            } else
            compOneMinus++;
            
            if (compare3(a, b, epsilon)) {
            compTwoplus++;
            } else {
            compOneMinus++;
            }

            if(compare4(a, b)) {
            compThreePlus++;
            } else {
            compThreeMinus++;
            }
            n--;
        }
        printf("Results with the entered epsilon of %f and without epsilon are as follows: ", epsilon);
        printf("Successful compares without epsilon: %d;\n1 - Unsuccessful compares without epsilon: %d;\n", compOnePlus, compOneMinus);
        printf("Successful compares with fixed epsilon: %d;\n2 - Unsuccessful compares fixed epsilon: %d;\n", compThreePlus, compThreeMinus);
        printf("Successful compares with dynamic epsilon: %d;\n3 -Unsuccessful compares dynamic epsilon: %d;\n", compFourPlus, compFourMinus);

    }

   

    return 0;

}

int compare1(double a, double b){
    return a == b;
}

int compare2(double a, double b){
    return fabs(a - b) < __FLT_EPSILON__;
}

int compare3(double a, double b, double eps){
    return fabs(a - b) < eps;
}

int compare4(double a, double b){
    return fabs(a - b) < __FLT_EPSILON__ * fmax(fabs(a), fabs(b));
}