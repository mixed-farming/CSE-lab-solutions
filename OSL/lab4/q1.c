#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc,char **argv)
{
    if(argc<2)
    {
        printf("Insufficient arguments\n");
        exit(1);
    }

    struct stat info;
    int return_value = stat(argv[1],&info);//on success they return 0

    if(return_value)
    {
        perror("stat");
        exit(1);
    }
    else
    {
        printf("File %s has inode number : %ld\n",argv[1],info.st_ino);
    }
}
