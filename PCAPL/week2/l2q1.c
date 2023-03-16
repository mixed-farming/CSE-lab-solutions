#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    int l,rank,size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    char a[100];
    if(rank==0)
    {
        printf("Enter message to be updated : ");
        scanf("%[^\n]%*c",a);
        l=strlen(a);
        MPI_Ssend(&l,1,MPI_INT,1,27,MPI_COMM_WORLD);
        // printf("Length sent\n");
        MPI_Ssend(a,l,MPI_CHAR,1,27,MPI_COMM_WORLD);
        // printf("Data sent\n");
        MPI_Recv(a,l,MPI_CHAR,1,27,MPI_COMM_WORLD,&status);
        printf("Updated data : %s\n",a);
    }
    else
    {
        MPI_Recv(&l,1,MPI_INT,0,27,MPI_COMM_WORLD,&status);
        // printf("\nLength received\n");
        MPI_Recv(a,l,MPI_CHAR,0,27,MPI_COMM_WORLD,&status);
        // printf("Data received\n");
        a[l]='\0';
        for(int i=0;i<l;i++)
        {
            if(a[i]>='a' && a[i]<='z')
            a[i]-=32;
            else if(a[i]>='A' && a[i]<='Z')
            a[i]+=32;
        }
        MPI_Ssend(a,l,MPI_CHAR,0,27,MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}