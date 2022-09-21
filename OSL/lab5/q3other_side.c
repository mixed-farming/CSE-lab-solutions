#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#define FIFO "my_fifo"

int main()
{
    int pfd;
    char buf[10];
    pfd=open(FIFO,O_WRONLY);
    if(pfd!=-1)
    {
        printf("Enter string : ");
        scanf("%s",buf);
        write(pfd,buf,sizeof(buf));
    }
    else
    {
        exit(1);
    }

    return 0;
}