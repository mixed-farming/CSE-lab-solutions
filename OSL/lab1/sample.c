#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd;
	char buffer[10];
	char msg[9]="Hey there";
	fd=open("temp.txt",O_RDWR);
	printf("File descriptor : %d\n",fd);
	if(fd!=-1)
	{
		write(fd,msg,sizeof(msg));
		lseek(fd,0,SEEK_SET);
		read(fd,buffer,sizeof(msg));
		printf("The content is %s\n\n",buffer);
		close(fd);
	}

	return 0;
}
