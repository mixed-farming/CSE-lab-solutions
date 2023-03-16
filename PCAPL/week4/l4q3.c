#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

void ErrorHandler(int err_code){
    if(err_code != MPI_SUCCESS){
        char error_string[BUFSIZ];
        int length_err_string, err_class;
        MPI_Error_class(err_code, &err_class);
        MPI_Error_string(err_code, error_string, &length_err_string);
        fprintf(stderr, "Error: %d %s\n", err_class, error_string);
    }
}

int main(int argc, char** argv){
    int rank, size, err_code,a[3][3],b[3],count=0,x,result=0;
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    err_code = MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank==0)
    {
        printf("Enter 9 elements : \n");
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("Enter element to be searched : ");
        scanf("%d",&x);
    }

    MPI_Bcast(&x,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(a,3,MPI_INT,b,3,MPI_INT,0,MPI_COMM_WORLD);

    for(int i=0;i<3;i++)
    {
        if(b[i]==x)
        {
            count++;
        }
    }
    
    err_code = MPI_Reduce(&count,&result,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    ErrorHandler(err_code);
    
    if(rank==0)
    printf("\n%d appears %d times in the matrix.\n",x,result);

    MPI_Finalize();
    return 0;   
}