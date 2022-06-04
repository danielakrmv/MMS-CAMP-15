# 0 "program.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "program.c"
int main(void)

{

    int num1, num2;

    printf("Enter first number: ");

    scanf("%d", &num1);

    printf("Enter second number: ");

    scanf("%d", &num2);

    printf("Before swap: Num1 = %d, Num2 = %d\n", num1, num2);

    swap(&num1, &num2);

    printf("After swap: Num1 = %d, Num2 = %d\n", num1, num2);

    return 0;

}
