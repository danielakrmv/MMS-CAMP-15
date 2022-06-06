#include <stdio.h>
#include <stdint.h>

void flipOddBits(uint64_t* mask);

int main(){
    uint64_t mask1 = 64;
    flipOddBits(&mask1);
    printf("%lu\n", mask1);
    return 0;

}

void flipOddBits(uint64_t* mask){
    for(unsigned long long i = 1; i < sizeof(*mask)*8; i+=2){
        *mask ^= (1llu << i);

    }

}