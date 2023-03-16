#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc,char** argv)
{
	int rank,size,len; 
    char s1[10],s2[10],recv1[10],recv2[10],store[20],result[20];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if (rank==0)
	{
        printf("Enter the length of string to be sent for every process : ");
        scanf("%d",&len);
		printf("Enter first string of length %d : ",size*len); 
        scanf("%s",s1);
		printf("Enter second string of length %d : ",size*len); 
        scanf("%s",s2);
	}

	MPI_Bcast(&len,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(s1,len,MPI_CHAR,recv1,len,MPI_CHAR,0,MPI_COMM_WORLD);
    MPI_Scatter(s2,len,MPI_CHAR,recv2,len,MPI_CHAR,0,MPI_COMM_WORLD); 

    int i=0,j=0,k=0;
    while(i<len)
    {
        store[k++]=recv1[i++];
        store[k++]=recv2[j++];
    }
    
	MPI_Gather(store,2*len,MPI_CHAR,result,2*len,MPI_CHAR,0,MPI_COMM_WORLD);
    result[len*size*2]='\0';
	if (rank==0) 
        printf("Resultant string: %s\n",result);
	MPI_Finalize();

    return 0;
}