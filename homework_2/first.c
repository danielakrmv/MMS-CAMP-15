#include <stdio.h>

int main(){
    double num1, num2, num3;
    double max;
    printf("Enter three nums:\n");
    while((fscanf(stdin, "%lf %lf %lf", &num1, &num2, &num3)) != EOF){
        if(num1 > num2 && num1 > num3){
            max = num1;
        }else if(num2 > num1 && num2 > num3){
            max = num2;

        }else if(num3 > num1 && num3 > num2){
            max = num3;
        }
        fprintf(stdout, "Max number is: %.2lf\n", max);
    }
    return 0;
}