#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int status;
    pid = fork();
    if(pid==0)
    {
        printf("Child PID : %d \tParent PID : %d\n",getpid(),getppid());
    }
    switch (pid)
    {
    case -1:
        printf("Error occured!...\n");
        exit(-1);
    case 0:
        sleep(5);
        printf("Executing child process...\nNow, Exiting child process...\n");
        printf("Child PID : %d \tParent PID : %d",getpid(),getppid());
        exit(0);
    default:
        // wait(&status);
        printf("Executing parent process...\nChild Status has returned: %d\nNow, Exiting parent process...\n",status);
        printf("Parent PID : %d\n",getpid());
    }
    return 0;
}