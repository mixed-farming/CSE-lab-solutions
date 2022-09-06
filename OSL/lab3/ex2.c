#include <sys/types.h>
#include <sys/wait.h>

void main()
{
    int status;
    pid_t pid;
    pid=fork();
    if(pid==-1)
    printf("\nERROR child not created");
    else if(pid==0)
    {
        printf("I'm the child\n");
    }
    else{
        wait(&status);
        printf("I'm the parent\n");
        printf("Child returned: %d\n",status);
    }
}