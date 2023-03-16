#include <mpi/mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv, char *argc[]){
	int rank, size,data;

	MPI_Init(&argv, &argc);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    int new;
    if(rank==0)
    {
        data=10;
        int err;
        err = MPI_Send(&data, 1, MPI_INT,0,27,MPI_COMM_WORLD);
        printf("Sent %d ",err);
        MPI_Recv(&new,1,MPI_INT,0,27,MPI_COMM_WORLD,&status);
        printf("%d received by rank %d in if block\n",new,rank);
        MPI_Send(&data, 1, MPI_INT,1,27,MPI_COMM_WORLD);
    }
    else
    {
        MPI_Recv(&new,1,MPI_INT,0,27,MPI_COMM_WORLD,&status);
        printf("%d received by rank %d in else block\n",new,rank);
    }
}

//older mpi versions(3.0.0 and below) cause deadlocks for this program. 
//Latest versions(4.0.0 and above) do not cause deadlock and are able to send the data in the above case.
