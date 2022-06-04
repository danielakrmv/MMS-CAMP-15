#include <stdio.h>
#include<string.h>

void baseconversion(char symbol[20], int, int);

int main(){
    char symbol[20];
    int base1, base2;
    printf("Enter the number, which want to be convert:\n");
    scanf("%s", symbol);
    printf("Enter the base");
    scanf("%d", &base1);
    printf("Enter the base to be converted");
    scanf("%d", &base2);
    baseconversion(symbol, base1, base2);
}

void baseconversion(char symbol[20], int b1, int b2){
    int count = 0, r, digit, i, n=0, b = 1;
    for(i=strlen(symbol) - 1; i >= 0 ;i --){
        if (symbol[i] >= 'A' && symbol[i]<='Z'){
            digit = symbol[i] - '0' - 7;
        }else{
            digit = symbol[i] - '0';
        }
        n = digit*b + n;
        b = b*b1;
    }
    while(n!=0){
        r = n % b2;
        digit = '0' + r;
        if(digit > '9'){
            digit += 7;
        }
        symbol[count] = digit;
        count ++;
        n = n/b2;
    }for(i=count - 1; i >= 0; i--){
        printf("%c", symbol[i]);
    }
    printf("\n");

}

