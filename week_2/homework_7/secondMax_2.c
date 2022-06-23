#include <stdio.h>

int secondMax(const int*, size_t, int*);

int main(){
    int sm;
    int arr[100];
    unsigned size;
    do{
        printf("Enter size:\n");
        scanf("%u", &size);
    }while(size<0 || size>10);

    for(int i=0; i < size; i++){
        printf("Enter element:\n");
        scanf("%d", &arr[i]);
    }

    if(secondMax(arr, size, &sm)){
        printf("Second max is: %d\n", sm);
    }

    if(size == 0){
        fprintf(stderr, "Array has zero elements!\n");
    }else if(size == 1){
        fprintf(stderr, "Array has only one elements!");
    }else if(secondMax(arr, size, &sm) == -1){
        fprintf(stderr, "First max el is equal with the second one!\n");
    }
    
    return 0;
}

int secondMax(const int* arr, size_t n, int* secondMax){
    int firstmax = *arr; //zadavam purviqt max el da e purviq el v masiva
    *secondMax = *(arr + 1); //vtoriqt max da e vtoriq element v masiva

    for(int i=1; i < n; i++){
        if(*(arr + i) > firstmax){
            *secondMax = firstmax; // za da moje vinagi firstmax da e po-golqm
            firstmax = *(arr + i);
        }else if(*(arr + i) > *secondMax){
            *secondMax = *(arr + i);
        }
    }
    if(firstmax == *secondMax){
        return -1;
    }
    return *secondMax;
}