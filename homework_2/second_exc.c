#include <stdio.h>

int main(){
    double a, b;
    printf("Enter two nums:\n");
    fscanf(stdin, "%lf %lf", &a, &b);
    if ((!a && b) || (a && !b)){
        fprintf(stdout, "1");
    }else{
        fprintf(stdout, "0");
    }
    return 0;
}