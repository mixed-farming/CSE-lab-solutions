#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int counter=0;
void* func(void *params)
{
    counter++;
}

void main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread1,0,func,0);
    pthread_create(&thread2,0,func,0);
    pthread_join(thread1,0);
    pthread_join(thread2,0);
}