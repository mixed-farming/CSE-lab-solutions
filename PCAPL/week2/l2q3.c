#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int rank,size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if(rank==0)
    {
        int a[size];
        int *buffer;
        int bsize = MPI_BSEND_OVERHEAD + size*sizeof(int);
        buffer=(int*)malloc(bsize);
        printf("Populate the array : ");
        for(int i=1;i<size;i++)
        {
            scanf("%d",&a[i]);
        }

        for(int i=1;i<size;i++)
        {
            MPI_Buffer_attach(buffer,bsize);
            MPI_Bsend((a+i),1,MPI_INT,i,27,MPI_COMM_WORLD);
            MPI_Buffer_detach(buffer,&bsize);
        }
    }
    else
    {
        int num;
        MPI_Recv(&num,1,MPI_INT,0,27,MPI_COMM_WORLD,&status);
        if(rank%2==0)
        printf("Process: %d\t Square of number = %d\n",rank,num*num);
        else
        printf("Process: %d\t Cube of number = %d\n",rank,num*num*num);
    }

    MPI_Finalize();
    return 0;
}