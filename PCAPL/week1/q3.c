#include <mpi.h>
#include <stdio.h>

int main(int argc,char** argv)
{
	int rank,size;
    int x=14,y=7;
	MPI_Init(&argc, &argv);//initialize MPI library
	MPI_Comm_size(MPI_COMM_WORLD,&size); //get number of processes
	MPI_Comm_rank(MPI_COMM_WORLD,&rank); // get my process id
    switch(rank)
    {
        case 0:
            printf("process %d: %d+%d=%d\n",rank,x,y,x+y);
            break;
        case 1:
            printf("process %d: %d-%d=%d\n",rank,x,y,x-y);
            break;
        case 2:
            printf("process %d: %d*%d=%d\n",rank,x,y,x*y);
            break;
        case 3:
            printf("process %d: %d/%d=%d\n",rank,x,y,x/y);
            break;
        default:
            printf("process %d\n",rank);
            break;
    }
	MPI_Finalize();//MPI clean up
	return 0;
}