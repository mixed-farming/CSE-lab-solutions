#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

char str[100],hold[100],result1[100],result2[100];
int l;

void* even_modifier(char* buf)
{
    for(int i=0;i<l;i++)
    {
        if(i%2==1)
        {
            buf[i]='$';
        }
        else
        {
            continue;
        }
    }

}

void* odd_modifier(char* buf)
{
    for(int i=0;i<l;i++)
    {
        if(i%2==0)
        {
            buf[i]='$';
        }
        else
        {
            continue;
        }
    }

}

int main()
{
    printf("Enter the input : ");
    // scanf("%[^\n]s", str)
    gets(str);
    strcpy(hold,str);
    l=strlen(str);

    pthread_t thread1;
    pthread_create(&thread1,0,&even_modifier,(void*)str);
    pthread_join(thread1,0);
    printf("Output from 1st thread : %s\n",str);

    pthread_t thread2;
    pthread_create(&thread2,0,&odd_modifier,(void*)hold);
    pthread_join(thread2,0);
    printf("Output from 2nd thread : %s\n",hold);

    return 0;   
}
