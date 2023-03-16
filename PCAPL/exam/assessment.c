#include "mpi.h"
#include <stdio.h>

int main(int argc,char** argv)
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Status status;

    int a[size],l,sum=0,b[size];
    if(rank==0)
    {
        printf("Enter the numbers : ");
        for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
        for(int i=1;i<size;i++)
        {
            MPI_Send(&a[i],1,MPI_INT,i,7,MPI_COMM_WORLD);
        }
    }
    else
    {
        MPI_Recv(&l,1,MPI_INT,0,7,MPI_COMM_WORLD,&status);
    }

    l*=(l*l);
    MPI_Gather(&l,1,MPI_INT,b,1,MPI_INT,0,MPI_COMM_WORLD);

    if(rank==0)
    {
        b[0]=(a[0]*a[0]*a[0]);
        for(int i=0;i<size;i++)
        {
            sum+=b[i];
            // printf("%d ",b[i]);
        }

        printf("Sum of cubes = %d\n",sum);
    }
    return 0;
}