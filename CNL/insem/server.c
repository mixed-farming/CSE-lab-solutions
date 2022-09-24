#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    int sockfd,newsockfd,clilen,n=1;
    int x,y,a[6],temp;
    struct sockaddr_in seraddr,cliaddr;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    seraddr.sin_port = htons(10200);
    bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
    listen(sockfd,2);
    clilen=sizeof(cliaddr);

    while(1)
    {
        newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
        printf("Connected to client %d",newsockfd);
        if(fork()==0)
        {
            for(int i=0;i<6;i++)
                read(newsockfd,&a[i],sizeof(int));

            for(int i=0;i<5;i++)//bubble sort
            {
                for(int j=0;j<5-i;j++)
                {
                    if(a[j+1]<a[j])
                    {
                        temp=a[j+1];
                        a[j+1]=a[j];
                        a[j]=temp;
                    }
                }
            }

            write(newsockfd,a,sizeof(a)*sizeof(int));
        }
    }

    return 0;
}
