#include "mpi.h"
#include <stdio.h>
#include <math.h>

int isPrime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        return 0;
    }

    if(x==1)
    return 0;

    return 1;
}

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
        for(int i=0;i<size;i++)
        {
            scanf("%d",&a[i]);
            MPI_Send(&a[i],1,MPI_INT,i,7,MPI_COMM_WORLD);
        }

        if(isPrime(a[0]))
        printf("Process: %d\t number %d is prime\n",rank,a[0]);
        else
        printf("Process: %d\t number %d is not prime\n",rank,a[0]);

    }
    else
    {
        MPI_Recv(&l,1,MPI_INT,0,7,MPI_COMM_WORLD,&status);

        if(isPrime(l))
        printf("Process: %d\t number %d is prime\n",rank,l);
        else
        printf("Process: %d\t number %d is not prime\n",rank,l);
    }

    MPI_Finalize();
    return 0;
}