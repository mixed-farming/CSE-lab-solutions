#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    int rank,size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    int a[size],l;
    if(rank==0)
    {
        printf("Populate the array : ");
        for(int i=1;i<size;i++)
        {
            scanf("%d",&a[i]);
            MPI_Send(&a[i],1,MPI_INT,i,7,MPI_COMM_WORLD);
        }

    }
    else
    {
        MPI_Recv(&l,1,MPI_INT,0,7,MPI_COMM_WORLD,&status);
        printf("Process : %d\t Received number : %d\n",rank,l);
    }

    MPI_Finalize();
    return 0;
}