#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char* argv[])
{
	int fd,nl=1; char ch;
	fd=open(argv[1],O_RDONLY,S_IRUSR|S_IXOTH);
	while(read(fd,&ch,1)==1)
	{
		printf("%c",ch);
		if(ch=='\n') nl++;		
		if(nl%21==0) 
		{ 
			nl++;
			getchar();  
		}
	}
	printf("\n");
	return 0;
}
