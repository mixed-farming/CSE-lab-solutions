#include "mpi.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int rank, size,a[10], b[10],even,odd,m,e[10],o[10];
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

    even=0;
    odd=0;
    for(int i=0;i<m;i++)
    {
        if(b[i]%2==0)
        {
            b[i]=1;
            even++;
        }
        else
        {
            b[i]=0;
            odd++;
        }
    }

    MPI_Gather(b, m, MPI_INT, a, m, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Gather(&even, 1, MPI_INT, e, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Gather(&odd, 1, MPI_INT, o, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        even=0;
        odd=0;
        for (int i = 0; i < size*m; i++)
        {   
            if(i<size)
            {
                even+=e[i];
                odd+=o[i];
            }
            printf("%d ",a[i]);
        }
        printf("\nEven count : %d",even);
        printf("\nOdd count : %d\n",odd);
    }
    MPI_Finalize();
    return 0;
}