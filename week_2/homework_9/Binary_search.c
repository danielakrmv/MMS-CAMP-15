#include <stdio.h>

int binarySearch(int*, size_t, int*);

int main(){
    int array[] = {2, 6, 13, 21, 60};
    int key;
    printf("Enter key:");
    scanf("%d", &key);
    printf("Searching element is on index: %d\n", binarySearch(array, 5, &key));

    return 0;
}

int binarySearch(int* arr, size_t n, int *key){
    int start = 0, end = n;
    int m = n / 2;

    while (m != start && m != end)
    {
        if(arr[m] == *key){
        
            return m;
        }
        else if(arr[m] > *key)
        {
            end = m;
        }
        else
        {
            start = m;
        }
        m = start + ((end - start) / 2);
    }

    return - 1;
}
