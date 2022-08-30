#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>



void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);

    while((entry = readdir(dp)) != NULL) 
    {
        lstat(entry->d_name,&statbuf);

            if(S_ISDIR(statbuf.st_mode)) 
            {
    /* Found a directory, but ignore . and .. */
                if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)// . - current directory(stays at the same directory) .. - moves to parent directory(moves back infinitely) -> both of which are hidden files 
                    continue;

                printf("%*s%s/\n",depth,"",entry->d_name);//prints directory
    /* Recurse at a new indent level */
                printdir(entry->d_name,depth+4);//printing depth number of space
            }

            else 
                printf("%*s%s\n",depth,"",entry->d_name);//prints file
    }
    chdir("..");
    closedir(dp);
}



int main()
{
    char buf[1024];
    getcwd(buf,sizeof(buf));//getting path of Current Working Directory
    int i=2;
    printdir(buf,i);
    return 0;
}
