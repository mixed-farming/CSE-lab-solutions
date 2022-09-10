    #include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *odd_sum_func(void* num)
{
    int *a = num;
    int n = a[0];
    int odd_sum=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]%2==1)//odd number check
            odd_sum+=a[i];
    }
    return (void*)odd_sum;
}

void *even_sum_func(void* num)
{
    int *a = num;
    int n = a[0];
    int even_sum=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]%2==0)//even number check
            even_sum+=a[i];
    }
    return (void*)even_sum;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Insufficient arguments\n");
        exit(1);
    }

    int n = argc - 1;
    int *a = (int *)calloc(n+1, sizeof(int));//static memory allocation also works
    a[0] = n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = atoi(argv[i]);
    }

    int even_sum = 0, odd_sum = 0;
    pthread_t even_thread, odd_thread;
    pthread_create(&odd_thread, 0, &odd_sum_func, (void*)a);
    pthread_create(&even_thread, 0, &even_sum_func, (void*)a);
    pthread_join(odd_thread, (void**)&odd_sum);   //parent thread waits until execution of odd_thread is completed
    printf("The Sum of Odd numbers is: %d\n", odd_sum);//this statement will print only after odd_sum_func has finished it execution
    pthread_join(even_thread, (void**)&even_sum); //parent thread waits until execution of even_thread is completed
    printf("The Sum of Even numbers is: %d\n", even_sum);
    return 0;
}