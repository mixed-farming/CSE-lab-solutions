#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fa,*fb;
    char ch,buffer[1024];
    fa=fopen("input.txt","r");
    fb=fopen("output.txt","w");

    if(!fa || !fb)
    {
        printf("Cannot open the file.");
        exit(1);
    }

    int i=0;
    while(ch!=EOF)
    {
        ch=getc(fa);
        buffer[i++]=ch;
    }

    for(int j=i-2;j>=0;j--)
    {
        ch=buffer[j];
        fputc(ch,fb);
        if(j==0)
        {
            printf("File content reversal is complete\n");
        }
    }

    fseek(fa,0,SEEK_END);
    int size=ftell(fa);
    printf("File size is : %d\n",size);

    return 0;
}