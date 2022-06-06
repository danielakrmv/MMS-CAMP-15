#include <stdio.h>
#include <stdint.h>

unsigned long bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);

int main()
{
    unsigned mask1 = 12;
    unsigned mask2 = 12;
    unsigned mask3 = 10;
    unsigned mask4 = 8;

    printf("%d\n", bitsNCount(mask1, mask2, mask3, mask4));
    return 0;
}

unsigned long bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4){
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;

    while ((mask1, mask2, mask3, mask4) != 0){
        count1 += mask1 & 1;
        mask1 >>= 1;
        count2 += mask2 & 1;
        mask2 >>= 1;
        count3 += mask3 & 1;
        mask3 >>= 1;
        count4 += mask4 & 1;
        mask4 >>= 1;
    }
    int count = count1 + count2 + count3 + count4;
    return count;
}