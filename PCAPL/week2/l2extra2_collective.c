#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int s;
    if (rank % 2 == 0)
    {
        int prod = 1;
        for (int i = 1; i <= (rank + 1); i++)
        {
            prod *= i;
        }
        MPI_Reduce(&prod, &s, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    }
    else
    {
        int sum = 0;
        for (int i = 1; i <= (rank + 1); i++)
        {
            sum += i;
        }
        MPI_Reduce(&sum, &s, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    }

    if(rank==0)
    {
        printf("Sum : %d\n",s);
    }

    MPI_Finalize();
    return 0;
}
