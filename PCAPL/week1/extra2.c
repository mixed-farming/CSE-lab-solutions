#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int x)
{
  for(int i=2;i<=sqrt(x);i++)
  {
    if(x%i==0)
    return 0;
  }
  return 1;
}

int main(int argc, char *argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    // set number of process to 9 during mpi run-time
    if (size != 2) {
    printf("This program must be run with exactly 2 processes.\n");
    MPI_Finalize();
    exit(1);
  }

    if(rank==0)
    {
        for(int i=2;i<=50;i++)
        {
          if(prime(i))
          printf("%d ",i);
        }
    }
    else
    {
       for(int i=51;i<=100;i++)
       {
          if(prime(i))
          printf("%d ",i);
       }

       printf("\n");
    }
return 0;
}