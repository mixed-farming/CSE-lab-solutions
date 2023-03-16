#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc,char** argv)
{
	int rank,size; 
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
    char s[100],recv[100],store[200],result[200];

	if (rank==0)
	{
		printf("Enter the string : "); 
        scanf("%s",s);
	}

    MPI_Scatter(s,1,MPI_CHAR,recv,1,MPI_CHAR,0,MPI_COMM_WORLD);
    
    int i=0,j=0,k=0;
    while(i<=size)
    {
        if(i<=rank)
        store[k++]=recv[j];
        else
        store[k++]='\t';//while doing Gather, the 'store' from every process should be of same length
        i++;
    }
    
	MPI_Gather(store,size,MPI_CHAR,result,size,MPI_CHAR,0,MPI_COMM_WORLD);
    result[size*size]='\0';
	if (rank==0)
    {
        printf("Resultant string: ");
        for(int i=0;i<size*size;i++)
        {
            if(result[i]!='\t')
            printf("%c",result[i]);
        }
        printf("\n");
    } 
        
	MPI_Finalize();

    return 0;
}
