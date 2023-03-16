#include "mpi.h"
#include <stdio.h>

int reverse(int x)
{
    int rev=0;
    while(x)
    {
        rev=rev*10+(x%10);
        x/=10;
    }

    return rev;
}

int main(int argc, char *argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int a[]={18, 523, 301, 1234, 2, 14, 108, 150, 1928}, b[9];
    b[rank]=reverse(a[rank]);// set number of process to 9 during mpi run-time 
    MPI_Finalize();
    printf("Process: %d\t number:%d\t reverse=%d\n",rank,a[rank],b[rank]);
return 0;
}