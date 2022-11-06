#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX 5

int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

void *thread_code(void *num)
{

    int *z = num;
    int m = z[0];
    int n = z[1];
    int p = z[2];
    int q = z[3];

    if (n != p)
    {
        printf("Not multiplicable!");
        exit(1);
    }
    else
    {
        printf("Populate the 1st matrix : ");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        printf("Populate the 2nd matrix : ");
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 5)
    {
        printf("Insufficient arguments\n");
        exit(1);
    }

    int m = atoi(argv[1]); // atoi() converts character string to integer value
    int n = atoi(argv[2]);
    int p = atoi(argv[3]);
    int q = atoi(argv[4]);

    int *z;
    z[0] = m;
    z[1] = n;
    z[2] = p;
    z[3] = q;

    pthread_t thread;
    pthread_create(&thread, 0, &thread_code, (void *)z); // create a thread
    pthread_join(thread, 0);                             // wait for termination of a thread

    printf("Multiplied matrix : \n");
    for (int i = 0; i < z[0]; i++)
    {
        for (int j = 0; j < z[3]; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}