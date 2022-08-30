#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]){
	int sfd,i=0,k=0;
	char ch[100], chr;
	if(argc!=3){
		//printf("%s %s",argv[0],argv[1]);
		printf("\nInsufficient Arguments\n");
		exit(1);
	}
	if((sfd=open(argv[2],O_RDONLY)) == -1){
		printf("File not found.\n");
		exit(2);
	}
	while((read(sfd, &chr, 1)) > 0){
		if(chr != '\n'){
			ch[i++] = chr;
		} else{
			k++;
			ch[i] = '\0';
			i=0;
			if(strstr(ch,argv[1]) != NULL){
				printf("Line : %d\t %s\n",k,ch);
			}
		}
	}
	exit(0);
}
