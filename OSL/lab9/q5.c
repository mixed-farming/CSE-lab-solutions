// WAP to demonstrate heap memory allocation
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr = (int *)calloc(5, sizeof(int));
    printf("Array:");
    for (int i = 0; i < 5; i++)
    {
        *(arr + i) = i * i;
        printf(" %d", *(arr + i));
    }
    return 0;
}
// Array: 0 1 4 9 16
