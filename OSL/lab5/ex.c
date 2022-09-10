#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_code(void *param)
{
    printf("In thread code\n");
}

int main()
{
    pthread_t thread;
    pthread_create(&thread,0,&thread_code,0);
    printf("In main thread\n");
    pthread_join(thread,0);
    return 0;
}
