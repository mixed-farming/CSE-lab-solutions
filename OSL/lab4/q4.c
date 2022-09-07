#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Insufficient arguments\n");
        exit(1);
    }
    char *oldpath = argv[1];
    char *newpath = "q4out.txt";
    struct stat info;
    printf("Before linking new link:\n");
    system("ls");
    int return_value = stat(oldpath, &info);
    if (return_value)
    {
        perror("stat");
        exit(1);
    }
    printf("Number of links before linking: %ld\n", info.st_nlink);
    symlink(oldpath, newpath);//symlink() is used to create a new soft link
    printf("After linking new link:\n");
    system("ls");
    int return_value_2 = stat(newpath, &info);
    if (return_value_2)
    {
        perror("stat");
        exit(1);
    }
    printf("Number of links after linking: %ld\nThe new path is: %s\n", info.st_nlink,newpath);
    unlink(newpath);
    printf("After unlinking new soft link:\n");
    system("ls");
    int return_value_3 = stat(oldpath, &info);
    if (return_value_3)
    {
        perror("stat");
        exit(1);
    }
    printf("Number of links after unlinking: %ld\n", info.st_nlink);
    return 0;
}