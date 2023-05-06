#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rank, size;
    int i, j, a[3][3], b[3], csum[3], sum = 0;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter 9 elements:\n");
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                scanf("%d", &a[i][j]);
    }

    for (i = 0; i < 3; i++)
        MPI_Scatter(&a[i][0], 1, MPI_INT, &b[i], 1, MPI_INT, 0, MPI_COMM_WORLD);
        //Scatter gives the very next address of &a[i][0] to the next process.

    for(i=0;i<3;i++)
        sum=sum+b[i];

    MPI_Gather(&sum, 1, MPI_INT, csum, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        for (i = 0; i < 3; i++)
            printf("Sum of column %d = %d \n", i+1, csum[i]);
    }

    MPI_Finalize();
    return 0;
}