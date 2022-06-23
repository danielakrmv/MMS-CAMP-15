#include <stdio.h>
#include <stdint.h>

#define TINT 1 //nomerata na flagovete mi
#define TDOUBLE 2
#define TFLOAT 3
#define TCHAR 4
#define TINT8 5
#define TINT16 6
#define TINT32 7
#define TINT64 8


void printValue(const void* valuePtr, uint8_t flag){
    if (flag == 1){
        printf("Int is: %d\n", *(int*)valuePtr);
    }
    else if(flag == 2){
        printf("Double is: %.2lf\n", *(double*)valuePtr);
    }
    else if(flag == 3){
        printf("Float is: %.2f\n", *(float*)valuePtr);
    }
    else if(flag == 4){
        printf("Char is: %c\n", *(char*)valuePtr);
    }
    else if(flag == 5){
        printf("Uint8 is: %u\n", *(uint8_t*)valuePtr);
    }
    else if(flag == 6){
        printf("Uint16 is: %u\n", *(uint16_t*)valuePtr);
    }
    else if(flag == 7){
        printf("Uint32 is: %u\n", *(uint32_t*)valuePtr);
    }
    else if(flag == 8){
        printf("Uint64 is: %lu\n", *(uint64_t*)valuePtr);
    }
    else{
        fprintf(stderr, "Input invalid!");
    }
}

int main(){
    int number = 14;
    printValue(&number,TINT);

    double num = 20.31;
    printValue(&num,TDOUBLE);

    float n = 10.5;
    printValue(&n,TFLOAT);

    char symb = '&';
    printValue(&symb,TCHAR);

    uint8_t ui8 = 8;
    printValue(&ui8,TINT8);

    uint16_t ui16 = 16;
    printValue(&ui16,TINT16);

    uint32_t ui32 = 32;
    printValue(&ui32,TINT32);

    uint64_t ui64 = 64;
    printValue(&ui64,TINT64);

    return 0;

}