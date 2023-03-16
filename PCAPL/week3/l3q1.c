#include "mpi.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int rank, size,a[10], b[10], c,sum=0,fact=1;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0)
    {
        printf("Enter %d values : ", size);
        for (int i = 0; i < size; i++)
            scanf("%d", &a[i]);
    }

    MPI_Scatter(a, 1, MPI_INT, &c, 1, MPI_INT, 0, MPI_COMM_WORLD);

    for(int i=1;i<=c;i++)
    fact*=i;

    MPI_Gather(&fact, 1, MPI_INT, b, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        for (int i = 0; i < size; i++)
        {
            sum+=b[i];
        }
        printf("The Result gathered in the root : %d\n",sum);
    }
    MPI_Finalize();
    return 0;
}