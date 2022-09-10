#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void thread_code(void *num)
{
    int *a = num;//making the first element of the array as formal parameter i.e. size of the series
    int n=a[0];
    a[1]=0;
    a[2]=1;

    for(int i=3;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
}
 
int main(int argc,char **argv)
{
    if(argc<2)
    {
        printf("Insufficient arguments\n");
        exit(1);
    }

    int n=atoi(argv[1]);//atoi() converts character string to integer value

    int *a=(int*)calloc(n,sizeof(int));//dynamic array initialized with n 0s

    a[0]=n;//parameter to be passed into the thread

    pthread_t thread;
    pthread_create(&thread,0,&thread_code,(void*)a);//create a thread
    pthread_join(thread,0);//wait for termination of a thread

    printf("The fibonacci series is : ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);//content at address of a[i] is updated by the thread_code
    }
    printf("\n");

    return 0;
}