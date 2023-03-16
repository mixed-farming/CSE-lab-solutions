#include <mpi.h>
#include <stdio.h>

int main(int argc,char** argv)
{
	int rank,size;
    int x=2;
	MPI_Init(&argc, &argv);//initialize MPI library
	MPI_Comm_size(MPI_COMM_WORLD,&size); //get number of processes
	MPI_Comm_rank(MPI_COMM_WORLD,&rank); // get my process id
	if(rank%2==0)
    {
        printf("Hello process %d\n",rank);
    }
    else
    {
        printf("World process %d\n",rank);
    }
	MPI_Finalize();//MPI clean up
	return 0;
}