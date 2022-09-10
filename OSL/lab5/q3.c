#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_code(void *num)
{
    int *arr = num;
    int start = arr[0];
    int end = arr[1];
    int *sieve = (int *)calloc(end, sizeof(int));
    for (int i=0;i<=end;i++)
    {
        sieve[i] = 1;
    }

    sieve[0] = 0;
    sieve[1] = 0;
    for(int i=2;i*i<=end;i++)
    {
        if (sieve[i]==1)
        {
            for (int j=i*i;j<=end; j=j+i)
            {
                sieve[j] = 0;
            }
        }
    }
    return (void *)sieve;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Insufficient arguments\n");
        exit(1);
    }

    int start = atoi(argv[1]);
    int end = atoi(argv[2]);

    int a[] = {start, end};
    int *result;
    pthread_t thread;
    pthread_create(&thread, 0, &thread_code, (void *)a);
    pthread_join(thread, (void **)&result);
    printf("Prime numbers between %d and %d (inclusive) are : ", start, end);

    for (int i = start; i <= end; i++)
    {
        if (result[i])
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}