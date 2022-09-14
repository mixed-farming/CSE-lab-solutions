#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fa,*fb,*fc;
    fa=fopen("input1.txt","r");
    fb=fopen("input2.txt","r");
    fc=fopen("ans.txt","w");

    if(!fa || !fb || !fc)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    char c1,c2;
    for(;;)
    {
        if(c1!=EOF)
        {
            c1=fgetc(fa);
            while(c1!='\n')
            {
                if(c1==EOF)
                {
                    break;
                }
                fputc(c1,fc);
                c1=fgetc(fa);
            }
            fputc('\n',fc);
        }

        if(c2!=EOF)
        {
            c2=fgetc(fb);
            while(c2!='\n')
            {
                if(c2==EOF)
                {
                    break;
                }
                fputc(c2,fc);
                c2=fgetc(fb);
            }
            fputc('\n',fc);
        }

        if(c1==EOF && c2==EOF)
        {
            printf("Merge process is complete.\n");
            break;
        }
    }
    return 0;
}