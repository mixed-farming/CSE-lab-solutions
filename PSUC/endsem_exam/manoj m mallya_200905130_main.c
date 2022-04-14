/*PSUC final lab exam*/
//Odd position is when both indices of the matrix are odd numbers.
//Even position is when both indices of the matrix are even numbers.

#include <stdio.h>
#include <stdlib.h>

int m,n;

void Replace(int a[100][100]){
    int i,j,sum,l;
    for(i=0;i<m;i++)
    for(j=0;j<n;j++){
        if((i%2==1 && j%2==1)&&(a[i][j]%2==0)){
            sum=0;
            while(a[i][j]>0){
                l=a[i][j]%10;
                sum+=l;
                a[i][j]/=10;
            }
            a[i][j]=sum;
        }
        else if((i%2==0 && j%2==0)&&(a[i][j]%2==1)){
            sum=0;
            while(a[i][j]>0){
                l=a[i][j]%10;
                sum=sum*10+l;
                a[i][j]/=10;
            }
            a[i][j]=sum;
        }
    }
}

int main()
{
    printf("Name : MANOJ M MALLYA\nRegistration number : 200905130\n\n");

    int i,j,mat[100][100],pro;
    printf("Enter the dimensions of the matrix : \n");
    scanf("%d %d",&m,&n);

    printf("\nEnter your elements : \n");

    for(i=0;i<m;i++)//reading the matrix
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    //displaying the matrix
    printf("\nEntered elements : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    //replacing digits by its product
    printf("\nAfter replacing all elements by Product of the digits : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            int pro=1;
            while(mat[i][j]>0)
            {
                pro = pro * (mat[i][j]%10);
                mat[i][j] = mat[i][j]/10;
            }
            mat[i][j]=pro;
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    printf("\nAfter function replace : \n");
    Replace(mat);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
