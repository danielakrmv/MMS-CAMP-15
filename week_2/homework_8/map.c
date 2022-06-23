#include <stdio.h>

void map(int *, int, int(*func)(int));
int multiplication(int number);

int main()
{
    int arr[] = {1, 2, 3, 4};
    map(arr, 4, multiplication);
    for(int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void map(int *array, int n, int(*func)(int))
{
    for(int i = 0; i < n; i++)
    {
        *(array + i) = func(array[i]);
    }
}

int multiplication(int number) //funkciq, koqto povdiga chislo na kvadrat
{
    number *= number;
    return number;
}