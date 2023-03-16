#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int i, j, a[size][size], b[size],max[size], min[size];
    if (rank == 0)
    {
        printf("Enter %d elements:",size*size);
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                scanf("%d", &a[i][j]);
    }

    MPI_Scatter(a, size, MPI_INT, b, size, MPI_INT, 0, MPI_COMM_WORLD);
    
    for (i = 0; i < size; i++)
    {
        MPI_Reduce(&b[i], &min[i], 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
        MPI_Reduce(&b[i], &max[i], 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    }

    MPI_Bcast(&max, size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&min, size, MPI_INT, 0, MPI_COMM_WORLD);

    for (i = 0; i < size; i++)
    {
        if (i == rank)
        {
            b[i] = 0;
        }
        else if (i > rank)
        {

            b[i] = min[rank];
        }
        else
        {

            b[i] = max[rank];
        }
    }

    MPI_Gather(b, size, MPI_INT, a, size, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        printf("The modified matrix is:\n");
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;
}
