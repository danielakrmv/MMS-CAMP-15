#include <stdio.h>
#include <stdint.h>

unsigned long onesCount(uint64_t mask);

int main()
{
    uint64_t mask = 64;
    unsigned long count = onesCount(mask);

    printf("%lu\n", count);
    return 0;
}

unsigned long onesCount(uint64_t mask)
{
    unsigned long count = 0;

    for(unsigned long i = 0; i < sizeof(mask) * __CHAR_BIT__; i++)
    {
        int check = !!((1ul<<i)&mask);
        if(check == 1)
        {
            count++;
        }
    }
    return count;
} 