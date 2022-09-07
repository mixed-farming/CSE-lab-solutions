#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

char const *perms(__mode_t mode)//mode_t present in <sys/stat.h>
{
	static char perminfo[16] = {0};
	int i = 0;
//user permissions
	perminfo[i++] = ((mode & S_IRUSR) ? 'r' : '-');
	perminfo[i++] = ((mode & S_IWUSR) ? 'w' : '-');
	perminfo[i++] = ((mode & S_IXUSR) ? 'x' : '-');
//group permissions                                                                                                            
	perminfo[i++] = ((mode & S_IRGRP) ? 'r' : '-');
	perminfo[i++] = ((mode & S_IWGRP) ? 'w' : '-');
	perminfo[i++] = ((mode & S_IXGRP) ? 'x' : '-');
//other permissions
	perminfo[i++] = ((mode & S_IROTH) ? 'r' : '-');
	perminfo[i++] = ((mode & S_IWOTH) ? 'w' : '-');
	perminfo[i++] = ((mode & S_IXOTH) ? 'x' : '-');
	return perminfo;
}

int main(int argc,char** argv)
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
        printf("File name: %s \nInode: %ld \nDevice node: %ld \nModes: %10.10s \nNumber of hard links pointing at the file:%ld \nUser id: %d \nGroup id: %d \nDevice id: %ld \nSize of the file : %ld bytes \nBlock size: %ld\nNumber of filesystem blocks allocated to the file: %ld \nFile was last accessed on: %sFile was last modified on: %sFile's metadata was last changed on: %s", argv[1], info.st_ino,info.st_dev, perms(info.st_mode), info.st_nlink, info.st_uid, info.st_gid, info.st_rdev, info.st_size, info.st_blksize, info.st_blocks, ctime(&info.st_atime), ctime(&info.st_mtime), ctime(&info.st_ctime));
    }
}