#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_code(void* num)
{
    int *a=num;
    int n=a[0];
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            sum+=a[i];
        }
    }

    return (void*)sum;
}

int main(int argc,char **argv)
{
    if(argc<2)
    {
        printf("Insufficient arguments\n");
        exit(1);
    }
    
    int n=argc-1;//number of numbers on the command line
    int *a=(int*)calloc(n+1,sizeof(int));
    a[0]=n;

    for(int i=1;i<=n;i++)
    {
        a[i]=atoi(argv[i]);
    }

    int sum = 0;
    pthread_t thread;
    pthread_create(&thread,0,&thread_code,(void*)a);
    pthread_join(thread,(void**)&sum);//2nd parameter is pointer to the location where the exit status of the thread mentioned in thread is stored.
    printf("Sum of given non-negative integers = %d\n",sum);

}