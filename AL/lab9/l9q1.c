#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int table[126],m,n,i,j,k,flag=0;//shift ascii table...ascii characters range from 33 to 126
    char str[100],substr[25];
    printf("Enter main string : ");//text string
    scanf("%s",str);
    n=strlen(str);
    printf("Enter the pattern string : ");//pattern string
    scanf("%s",substr);
    m=strlen(substr);
    for(i=0;i<126;i++)//initializing the table
        table[i]=m;
    for(j=0;i<=m-2;j++)//assigning values for substr characters
        table[substr[j]]=m-1-j;
    i=m-1;//setting i to last index of text string
    while(i<=n-1)
    {
        k=0;
        if(k<=m-1 && substr[m-1-k]==str[i-k])
            k++;
        if(k==m)
        {
            printf("Pattern is found at position %d on the text string.\n",i-(m-1)+1);
            flag=1;
            break;
        }
        else
            i=i+table[str[i]];
    }
    if(!flag)
    {
        printf("Pattern is not found in the text string.\n");
    }
    return 0;
}