#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    int rank,size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    int n;
    if(rank==0)
    {
        n=1;
        MPI_Send(&n,1,MPI_INT,rank+1,rank+1,MPI_COMM_WORLD);
        MPI_Recv(&n,1,MPI_INT,size-1,rank,MPI_COMM_WORLD,&status);
        printf("Final value of number: %d\n",n);
    }
    else
    {
        MPI_Recv(&n,1,MPI_INT,rank-1,rank,MPI_COMM_WORLD,&status);
        if((rank)%2==1)
        {
            int sum=0;
            for(int i=1;i<=(rank+1);i++)
            {
                sum+=i;
            }
            n+=sum;
            MPI_Send(&n,1,MPI_INT,(rank+1)%size,(rank+1)%size,MPI_COMM_WORLD);
        }
        else
        {
            int prod=1;
            for(int i=1;i<=(rank+1);i++)
            {
                prod*=i;
            }
            n+=prod;
            MPI_Send(&n,1,MPI_INT,(rank+1)%size,(rank+1)%size,MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}