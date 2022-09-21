#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#define FIFO "my_fifo"//pathname

int main()
{
    int res,pfd,num[4],i=0;
    if(access(FIFO,F_OK)==-1)//if the file is inaccessible
    {
        res=mkfifo(FIFO,0777);
        if(res!=0)
        {
            fprintf(stderr,"Couldn't create fifo %s",FIFO);
            exit(1);
        }
    }
    pfd=open(FIFO,O_WRONLY);
    for(;i<4;i++)
    {
        printf("Enter number %d : ",i+1);
        scanf("%d",&num[i]);
    }

    if(pfd!=-1)
    {
        res=write(pfd,num,sizeof(num));
        if(res==-1)
        {
            fprintf(stderr,"Write Error : ");
            exit(1);
        }
        close(pfd);
    }
    else
    {
        exit(1);
    }

    printf("Process %d finished",getpid());
    return 0;
}