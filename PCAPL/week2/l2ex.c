#include "mpi.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    int n,rank,size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if(rank==0)
    {
        printf("Enter a number to be sent : ");
        scanf("%d",&n);
        MPI_Send(&n,1,MPI_INT,1,1,MPI_COMM_WORLD);
        printf("Data sent\n");
    }
    else
    {
        MPI_Recv(&n,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        printf("\nData received from master process = %d\n",n);
    }

    MPI_Finalize();
    return 0;
}