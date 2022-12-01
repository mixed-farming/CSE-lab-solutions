#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char c;
    printf("Direction of movement (l/r) : ");
    scanf("%c",&c);
    printf("Enter the number of requests : ");
    scanf("%d",&n);
    int a[n];
    printf("Populate the request sequence : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int k;
    printf("Enter the initial head position : ");
    scanf("%d",&k);
    int l;
    printf("Enter the last track on the disk : ");
    scanf("%d",&l);

    int cylinder=0;

    //sorting
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    int lfinal,rfinal;
    for(int i=0;;i++)
    {
        lfinal=a[i];
        if(a[i]>k)
        {
            break;
        }
    }

    for(int i=n-1;;i--)
    {
        rfinal=a[i];
        if(a[i]<k)
        {
            break;
        }
    }

    if(c=='l')
    {
        cylinder=k+l+(l-lfinal);
        printf("Total head movement is %d\n",cylinder);
    }
    else
    {
        cylinder=(l-k)+l+rfinal;
        printf("Total head movement is %d\n",cylinder);
    }
}