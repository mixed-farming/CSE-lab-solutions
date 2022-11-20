#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int wt[100], bt[100], at[100], tat[100], n, p[100];//waiting time, burst time, arrival time, turnaround time
float awt[5], atat[5];//average waiting time, average turnaround time
int temp1, temp2, temp3, sqt, avg;

void input()
{
    printf("Enter Number of processes : ");
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
        p[i] = i + 1;//numbering the i-th process for reference
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time of process %d : ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter Arrival Time of process %d : ", i + 1);
        scanf("%d", &at[i]);
    }
    for (i = 0; i < 5; i++)
    {
        awt[i] = 0.0;
        atat[i] = 0.0;
    }
}

void changeArrival()
{
    int a = at[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (at[i] < a)
            a = at[i];
    }
    if (a != 0)
    {
        for (i = 0; i < n; i++)
            at[i] = at[i] - a;//relative arrival time
    }
}

void precalc()
{
    int bt1[n], i, j, temp, qt;//qt - dynamic quantum time 
    int b[n];
    float twt, ttat;
    for (i = 0; i < n; i++)
        bt1[i] = bt[i];
    for (i = 0; i < n; i++)
        b[i] = bt[i];
    int num = n;
    int time = 0;
    int max;
    int sum, t, a, ap;
    ap = 0;
    // sorting in ascending order
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                temp1 = bt[j];//swapping all the parameters
                temp2 = p[j];
                temp3 = at[j];
                bt[j] = bt[j + 1];
                p[j] = p[j + 1];
                at[j] = at[j + 1];
                bt[j + 1] = temp1;
                p[j + 1] = temp2;
                at[j + 1] = temp3;
            }
        }
    }
    max = bt[n - 1];
    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + bt[i];
    }
    avg = sum / n;
    qt = (avg + max) / 2; // qt = average (average (burst time), highest burst time) 
    printf("\nDynamic Quantum time calculated is : %d\n\n", qt);
    while (num > 0)
    {
        a = 0;
        max = 0;
        sum = 0;
        t = 0;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && b[i] != 0)
            {
                if (b[i] < qt)
                {
                    t += b[i];
                    b[i] = 0;
                }
                else
                {
                    t += qt;
                    b[i] -= qt;
                }
                if (b[i] < qt && b[i] != 0)
                {
                    t += b[i];
                    b[i] = 0;
                }
                if (b[i] == 0)
                {
                    wt[i] = (time + t) - bt1[i];
                    tat[i] = time + t;
                    num--;
                }
            }
        }
        time += t;
    }
    printf("Processes\tWaitingtime\tTurnAroundTime\n");
    for (j = 1; j <= n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (j == p[i])
                printf("process %d\t%d\t\t%d\n", p[i], wt[i], tat[i]);
        }
    }
    twt = 0;
    ttat = 0;
    for (i = 0; i < n; i++)
    {
        twt = twt + wt[i];
    }
    awt[4] = twt / n;
    for (i = 0; i < n; i++)
    {
        ttat = ttat + tat[i];
    }
    atat[4] = (ttat / n);
}

void display(int c)
{
    int i;
    printf("\nAverage Waiting time:%f\nAverage Turn Around Time:%f\n", awt[c - 2], atat[c - 2]);
}
 
int main()
{
    char c;
    printf("\t\t***Welcome to modified round robin CPU scheduling***\n\n");
    input();
    changeArrival();
    precalc();
    display(6);
    return 0;
}
