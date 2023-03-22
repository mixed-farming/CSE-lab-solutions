/*

Question : Take five 5 letter word inputs from user and a small string in the root process.
Scatter the words among 5 processes.
Check the occurence of the small string in each string.
If there is atleast one occurence of it then print 1 else print 0.
The printing process should happen in the root.
Use collective communications except for the final gathering of the result. 

*/

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv)
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Status status;
    char str[5][5],sub[5],a[5];
    int b[5],l;
    if(rank==0)
    {
        printf("Enter the strings : \n");
        for(int i=0;i<5;i++)
        {
            scanf("%s",str[i]);
        }
        printf("Enter the substring to be searched for : ");
        scanf("%s",sub);
        l=strlen(sub);
    }
    
    MPI_Bcast(&l,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Bcast(sub,l,MPI_CHAR,0,MPI_COMM_WORLD);
    MPI_Scatter(str,5,MPI_CHAR,a,5,MPI_CHAR,0,MPI_COMM_WORLD);
    
    int flag=0,i,j,k;
    for(i=0;i<=5-l;i++)
    {
        k=i;
        for(j=0;j<l;j++)
        {
            if(a[k]==sub[j])
            k++;
            else
            break;
        }

        if(j==l)
        {
            flag=1;
            break;
        }
    }

    if(rank!=0)
    {
        MPI_Send(&flag,1,MPI_INT,0,7,MPI_COMM_WORLD);
    }
    else
    {
        printf("Process : %d\tresult : %d\n",rank,flag);
        int x;
        for(i=1;i<5;i++)
        {
            MPI_Recv(&x,1,MPI_INT,i,7,MPI_COMM_WORLD,&status);
            printf("Process : %d\tresult : %d\n",i,x);
        }
    }

    MPI_Finalize();
    return 0;
}