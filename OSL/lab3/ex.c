#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid=fork();//fork another process
    if(pid<0)//error occured
    {
        fprintf(stderr,"Fork Failed\n");
        exit(1);
    }
    else if(pid==0)//child process
    {
        execlp("bin/ls","ls",NULL);
    }
    else//parent process
    {//parent will wait for the child to complete
        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }

    return 0;
}
