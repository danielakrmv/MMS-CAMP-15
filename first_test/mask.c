#include <stdio.h>
#include <stdint.h>

void mirrorBits(uint16_t* mask);

int main(){
    uint16_t mask1 = 0b1111111100000000;
    void res = mirrorBits(mask1);
}

void mirrorBits(uint16_t* mask){
     uint16_t *mask1 = 0b1111111100000000;
     for(int bit = 15; bit >= 0; bit--){
         if(!!(*mask1 & (1 << bit)) == 0){
             *mask = *mask ^ (1 << bit);
         }else if(!!(*mask1 & (1 << bit)) == 1){
             *mask = *mask ^ (1 << bit);
         }
     }

}