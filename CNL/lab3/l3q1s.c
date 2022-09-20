#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<fcntl.h>
#define PORTNO 10200
void main()
{
	struct sockaddr_in seraddr,cliaddr; int sockfd,len,i,j,r,c,arr[10][10];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	seraddr.sin_port=htons(PORTNO);
	bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
	len=sizeof(cliaddr);
	recvfrom(sockfd,&r,sizeof(r),0,(struct sockaddr*)&cliaddr,&len);
	recvfrom(sockfd,&c,sizeof(c),0,(struct sockaddr*)&cliaddr,&len);
	for (i=0;i<r;i++)
	{
		recvfrom(sockfd,arr[i],sizeof(int)*c,0,(struct sockaddr*)&cliaddr,&len);
		printf("Row %d:",i+1);
		for (j=0;j<c;j++) printf("%d ",arr[i][j]);
		printf("\n");
	}
	sendto(sockfd,arr,sizeof(arr),0,(struct sockaddr*)&cliaddr,len);
	printf("2D array sent\n");
}