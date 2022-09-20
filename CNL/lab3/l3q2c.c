#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <time.h>

#define PORTNO 10200

typedef struct response
{
	char code_val[50];
	char url[50];
	char version[50];
	char msg[50];
	int code;
} response;

typedef struct request
{
	char method[50];
	char url[50];
	char version[50];
	char msg[50];
} request;

int main()
{
	struct sockaddr_in address;
	int sockfd;
	char buf[10];
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORTNO);
	int len = sizeof(address);
	request req;
	response res;

	strcpy(req.method, "Post");
	strcpy(req.url, "www.youtube.com");
	strcpy(req.version, "HTTP/1.1");
	strcpy(req.msg, "Message here");
	int m=sendto(sockfd,&req,sizeof(req),0,(struct sockaddr*)&address,len);
	int n=recvfrom(sockfd,&res,sizeof(res),0,(struct sockaddr*)&address,&len);

	printf("Response received : Version - %s \nCode : %d \nURL - %s \nMessage - %s \nValue - %s\n",res.version,res.code,res.url,res.msg,res.code_val);

	return 0;
}