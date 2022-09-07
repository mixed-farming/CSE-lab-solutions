#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Insufficient arguments\n");
        exit(1);
    }

    char *oldpath = argv[1];
    char *newpath = "q3out.txt";
    struct stat info;
    printf("Before linking new link : \n");
    system("ls"); //system() present in <stdlib>
    int return_value = stat(oldpath, &info);
    if (return_value)
    {
        perror("stat"); //the following string will be prepended to the error description
        exit(1);
    }
    printf("Number of links before linking : %ld\n\n", info.st_nlink);
    link(oldpath, newpath); //link is used to create a new hard link
    printf("After linking new link : \n");
    system("ls");
    int return_value_2 = stat(newpath, &info);
    if (return_value_2)
    {
        perror("stat");
        exit(1);
    }
    printf("Number of links after linking: %ld\nThe new path is: %s\n\n", info.st_nlink,newpath);
    unlink(newpath);
    printf("After unlinking new link:\n");
    system("ls");
    int return_value_3 = stat(oldpath, &info);
    if (return_value_3 != 0)
    {
        perror("stat");
        exit(1);
    }
    printf("Number of links after unlinking: %ld\n", info.st_nlink);
    return 0;
}