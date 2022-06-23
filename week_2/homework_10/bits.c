#include <stdio.h>
#include <stdint.h>
#include <string.h>

void printBits(uint64_t num){
    union u{
        uint64_t a;
        double b; //double sum go zapisala vurhu int 
    }u;
    u.b = num;
    for(int i = 63; i >= 0; i--){
        printf("%llu", (u.a & (1ull << i)) >> i);
    }
}

int main(){
    uint64_t num = 20;
    printBits(num);
    return 0;
}