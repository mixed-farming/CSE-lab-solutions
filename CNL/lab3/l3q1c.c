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
	struct sockaddr_in address; int sockfd,buf[10],twod[10][10],i,j,r,c;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=htons(PORTNO);
	int len=sizeof(address);
	printf("Enter row size: "); scanf("%d",&r);
	sendto(sockfd,&r,sizeof(r),0,(struct sockaddr*)&address,len);
	printf("Enter column size: "); scanf("%d",&c);
	sendto(sockfd,&c,sizeof(c),0,(struct sockaddr*)&address,len);
	for (i=0;i<r;i++)
	{
		printf("Enter elements of row %d: ",i+1);
		for (j=0;j<c;j++) scanf("%d",&buf[j]);
		sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&address,len);
	}
	recvfrom(sockfd,twod,sizeof(twod),0,(struct sockaddr*)&address,&len);
	printf("Received matrix:\n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++) 
		printf("%d ",twod[i][j]);
		printf("\n");
	}
}