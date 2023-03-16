#include <mpi.h>
#include <stdio.h>

int main(int argc,char** argv)
{
	int rank,size;
	MPI_Init(&argc, &argv);//initialize MPI library
	MPI_Comm_size(MPI_COMM_WORLD,&size); //get number of processes
	MPI_Comm_rank(MPI_COMM_WORLD,&rank); // get my process id
	printf("Process %d of %d: Hello world\n",rank,size);
	MPI_Finalize();//MPI clean up
	return 0;
}