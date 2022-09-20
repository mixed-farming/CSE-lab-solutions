#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORTNO 10200

typedef struct request
{
	char method[50];
	char url[50];
	char version[50];
	char msg[50];
} request;

typedef struct response
{
	char code_val[50];
	char url[50];
	char version[50];
	char msg[50];
	int code;
} response;

int main()
{
	struct sockaddr_in seraddr, cliaddr;
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	int len = sizeof(cliaddr);
	
	request req;
	response res;

	int m=recvfrom(sockfd,&req,sizeof(req),0,(struct sockaddr*)&cliaddr,&len);

	strcpy(res.msg,req.msg);
	strcpy(res.url,req.url);
	strcpy(res.version,req.version);
	res.code=200;
	strcpy(res.code_val,"DONE");
	printf("Request received : Version - %s \nMethod - %s \nURL - %s \nMessage - %s \n",req.version,req.method,req.url,req.msg);
	int n=sendto(sockfd,&res,sizeof(res),0,(struct sockaddr*)&cliaddr,len);

	return 0;
}