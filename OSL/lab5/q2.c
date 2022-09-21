#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int n,fd[2];
    char *buf1="Hello...I typed this code",buf2[1024];
    pipe(fd);//system call for pipe
    //fd[0] is the file descriptor for read 
    //fd[1] is the file descriptor for write
    write(fd[1],buf1,strlen(buf1));
    n=read(fd[0],buf2,sizeof(buf2));
    if(n>=0)
    {
        buf2[n]='\0';//terminating the string buf2
        printf("Received : %s\n",buf2);
    }
    else
    {
        perror("READ ");
    }
    
    return 0;
}
