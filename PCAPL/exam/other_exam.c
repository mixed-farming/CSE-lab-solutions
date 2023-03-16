/*
Accept two 4×4 matrices, A & B, and add the max element of each column of A 
to the min element of each row of B using 4 processes.
Also, if the principal diagonal element of B isn't the minimum element, then replace it with 0.
And use only collective communication functions, and do not transpose the matrix.
Sample:

A
1 2 3 4 
5 6 7 8 
9 10 11 12
13 14 15 16

B
16 15 14 13
12 11 10 9 
8 7 6 5
4 3 2 1

o/p:
0 15 14 26
12 0 10 23
8 7 0 20
4 3 2 17

*/

#include <stdio.h>
#include <mpi.h>

int main(int argc,char** argv)
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int a[4][4],b[4][4],row[4],col[4],min[4],max[4],temp[4],c[4][4],flag;
    if(rank==0)
    {
        printf("Populate the elements of 1st matrix : \n");
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("Populate the elements of 2nd matrix : \n");
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
    }

    for(int i=0;i<4;i++)
        MPI_Scatter(&b[i][0],1,MPI_INT,&row[i],1,MPI_INT,0,MPI_COMM_WORLD);//B scattered column-wise to find row minimum using Reduce

    MPI_Scatter(a,4,MPI_INT,col,4,MPI_INT,0,MPI_COMM_WORLD);//A scattered row-wise to find column maximum using Reduce
    MPI_Scatter(b,4,MPI_INT,temp,4,MPI_INT,0,MPI_COMM_WORLD);//B scattered row-wise to get modified

    for(int i=0;i<4;i++)
    {
        MPI_Reduce(&col[i],&max[i],1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);
        MPI_Reduce(&row[i],&min[i],1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
    }

    MPI_Bcast(&max, 4, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&min, 4, MPI_INT, 0, MPI_COMM_WORLD);

    for(int i=0;i<4;i++)
    {
        if(temp[i]==min[rank])
        {
            temp[i]+=max[rank];
            flag=i;
            break;
        }
    }
    if(temp[rank]!=min[rank] && flag!=rank)
    temp[rank]=0;

    MPI_Gather(temp,4,MPI_INT,c,4,MPI_INT,0,MPI_COMM_WORLD);
    if(rank==0)
    {
        printf("\nModified matrix : \n");
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }
    MPI_Finalize();
    return 0;
}