#include "mpi.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int rank, size,a[10], b[10],sum=0,m;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0)
    {
        printf("Enter number of values to be sent for a process : ");
        scanf("%d",&m);
        printf("Enter %d values : ", m*size);
        for (int i = 0; i < size*m; i++)
            scanf("%d", &a[i]);
    }
    
    MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(a, m, MPI_INT, b, m, MPI_INT, 0, MPI_COMM_WORLD);

    for(int i=0;i<m;i++)
    sum+=b[i];

    sum/=m;

    MPI_Gather(&sum, 1, MPI_INT, b, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        for (int i = 0; i < size; i++)
        {
            sum+=b[i];
            // printf("%d ",b[i]);
        }
        printf("The Result gathered in the root : %d\n",sum/size);
    }
    MPI_Finalize();
    return 0;
}