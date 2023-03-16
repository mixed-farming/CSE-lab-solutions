#include <mpi.h>
#include <stdio.h>
#include <ctype.h>

char* update(char a[],int rank)
{
    if(a[rank]>='a' && a[rank]<='z')
    a[rank]=a[rank]-32;//or a[rank]=toupper(a[rank]);
    else
    a[rank]=a[rank]+32;//or a[rank]=tolower(a[rank]);
    return a;
}

int main(int argc,char** argv)
{
	int rank,size;
	MPI_Init(&argc, &argv);//initialize MPI library
	MPI_Comm_size(MPI_COMM_WORLD,&size); //get number of processes
	MPI_Comm_rank(MPI_COMM_WORLD,&rank); // get my process id
    char a[]="HeLlo";
    printf("Process: %d \tUpdated message : %s\n",rank,update(a,rank));
	MPI_Finalize();//MPI clean up
	return 0;
}