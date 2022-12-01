#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
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
    int seek_count=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            seek_count+=abs(k-a[i]);
        }
        else
        {
            seek_count+=abs(a[i-1]-a[i]);
        }
    }
    printf("\nNo of cylinders = %d\n",seek_count);
}