#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc,char** argv)
{
	int rank,size; 
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
    char s[1000],recv[1],store[2000],result[2000]="";

	if (rank==0)
	{
		printf("Enter first string of length %d : ",size); 
        scanf("%s",s);
        s[size]='\0';
	}

    MPI_Scatter(s,1,MPI_CHAR,recv,1,MPI_CHAR,0,MPI_COMM_WORLD);

    int i=0,k=0;
    while(i<=rank)
    {
        store[k++]=recv[0];
        i++;
    }

	if (rank==0) 
        printf("Resultant string: %s",store);
    else
        printf("%s",store);

    if(rank==size-1)
    printf("\n");
    
	MPI_Finalize();

    return 0;
}