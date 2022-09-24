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
    int sockfd,len;
    int x,y,a[6],b[6],temp,count=0;
    struct sockaddr_in address;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr("127.0.0.1");
    address.sin_port=htons(10200);

    len=sizeof(address);
    int r=connect(sockfd,(struct sockaddr *)&address,len);

    while(1)
    {
        printf("\n\nEnter the limits : ");
        scanf("%d %d",&x,&y);

        printf("Enter 6 odd numbers in the interval %d and %d\n",x,y);
        while(count<6)
        {
            printf("Enter odd number : ");
            scanf("%d",&temp);
            if(temp%2==1 && temp<=y && temp>=x)
            {
                a[count]=temp;
                write(sockfd,&a[count],sizeof(int));
                count++;
            }
        }

        // for(int i=0;i<6;i++)
        // {
        //     printf("%d ",a[i]);
        // }
        
        printf("\nSorted array : ");
        read(sockfd,b,sizeof(b)*sizeof(int));
        for(int i=0;i<6;i++)
        {
            printf("%d ",b[i]);
        }
    }
    return 0;
}
