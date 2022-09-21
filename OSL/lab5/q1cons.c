#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#define FIFO "my_fifo"

int main()
{
    int res,pfd,buf[4],i=0;
    printf("Process %d opening FIFO O_WRONLY\n", getpid());
    pfd=open(FIFO,O_RDONLY);
    if(pfd!=-1)
    {
        res=read(pfd,buf,sizeof(buf));
        printf("Received : ");
        for(;i<4;i++)
        {
            printf("%d\t",buf[i]);
        }

        printf("\n");
        close(pfd);
    }
    else
    {
        exit(1);
    }

    printf("Process %d finished\n",getpid());
    return 0;
}