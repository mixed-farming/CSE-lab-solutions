#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define INT_MAX 2147483647
typedef struct { int pid,burstTime,arrivalTime; } Process;

void pline(int x);
void FCFS(Process proc[],int n)
{
    int sum=0; Process temp; int wt[n];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1 ; j++)
        {
            if (proc[j].arrivalTime > proc[j + 1].arrivalTime)
            {
                temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
    wt[0]=0;
    for (int i = 1; i < n; i++)
    {
        sum = sum + proc[i-1].burstTime;
        wt[i]=sum;
    }
    sum = 0;
    printf("**FCFS**\nPID\tArrival\tBurst\tWaiting\n");
    pline(44);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].arrivalTime, proc[i].burstTime,wt[i]);
        sum += wt[i];
    }
    pline(44); printf("Average Waiting Time : %.3f\n\n",(float)sum/(float)n);
}
void pline(int x)
{   int i;
    for (i = 0; i < x; i++) printf("-");
    printf("\n");
}

void swap(Process *p1,Process *p2)
{
  int temp=p1->pid; p1->pid=p2->pid; p2->pid=temp;
  temp=p1->burstTime; p1->burstTime=p2->burstTime; p2->burstTime=temp;
  temp=p1->arrivalTime; p1->arrivalTime=p2->arrivalTime; p2->arrivalTime=temp;
}
void findWaitingTimeSJF(Process proc[],int n,int wt[])
{
  for (int i=0;i<n;i++)
    for (int j=0;j<n-i-1;j++)
      if (proc[j].arrivalTime>proc[j+1].arrivalTime) swap(&proc[j],&proc[j+1]);
  for (int i=0;i<n;i++)
    for (int j=0;j<n-i-1;j++)
      if (proc[j].arrivalTime==proc[j+1].arrivalTime)
        if (proc[j].burstTime>proc[j+1].burstTime) swap(&proc[j],&proc[j+1]);
  wt[0]=0;
  for (int i=1;i<n;i++) wt[i]=wt[i-1]+proc[i-1].burstTime-proc[i].arrivalTime;
}
void SJF(Process proc[], int n)
{
    int wt[n],total_wt = 0;
    findWaitingTimeSJF(proc, n, wt);
    printf("**SJF**\nProcess\t\tBurstT\t\tWaitT\t\t\n");
    for (int i = 0; i < n; i++)
    {
        total_wt+=wt[i];
        printf(" %d\t\t %d\t\t %d\n",proc[i].pid, proc[i].burstTime, wt[i]);
    }
    printf("Average waiting time = %f\n\n",(float)total_wt/(float)n);
}

void findWaitingTimeSRTF(Process proc[],int n,int wt[])
{
    int rt[n];
    // Copy the burst time into rt[]
    for (int i = 0; i < n; i++) rt[i] = proc[i].burstTime;
    int complete=0,t=0,minm=INT_MAX,shortest=0,finish_time;
    bool check=false;
    while (complete!=n)
    {
        // Find process with minimum
        // remaining time among the
        // processes that arrives till the
        // current time
        for (int j=0;j<n;j++)
        {
            if ((proc[j].arrivalTime<=t) && (rt[j]<minm) && rt[j]>0)
            {
                minm=rt[j]; shortest=j; check=true;
            }
        }
        if (check==false) { t++; continue; }
        rt[shortest]--; // Reduce remaining time by one
        minm=rt[shortest]; // Update minimum
        if (minm==0) minm=INT_MAX;
        if (rt[shortest]==0) // If a process gets completely executed
        {
            // Increment complete
            complete++;
            check=false;
            // Find finish time of current
            // process
            finish_time=t+1;
            // Calculate waiting time
            wt[shortest] = finish_time - proc[shortest].burstTime - proc[shortest].arrivalTime;
            if (wt[shortest]<0) wt[shortest]=0;
        }
        // Increment time
        t++;
    }
}
// Function to calculate turn around time
void findTurnAroundTime(Process proc[],int n,int wt[],int tat[])
{
    // calculating turnaround time by adding
    // burstTime[i] + wt[i]
    for (int i=0;i<n;i++) tat[i] = proc[i].burstTime + wt[i];
}
void SRTF(Process proc[], int n)
{
    int wt[n],tat[n],total_wt=0,total_tat=0;
    // Function to find waiting time of all processes
    findWaitingTimeSRTF(proc,n,wt);
    // Function to find turn around time for all processes
    findTurnAroundTime(proc,n,wt,tat);
    // Display processes along with all details
    printf("**SRTF**\nPID\t\tBT\t\tWT\t\tTAT\t\t\n"); // Calculate total waiting time
    for (int i=0;i<n;i++)
    {
        total_wt+=wt[i]; total_tat+=tat[i];
        printf(" %d\t\t %d\t\t %d\t\t %d\t\t\n",proc[i].pid,proc[i].burstTime,wt[i],tat[i]);
    }
    printf("Average waiting time = %f\n\n", (float)total_wt / (float)n);
}

void RR(Process proc[],int n)
{
    int i,total = 0,checker = 0,y,time_quantum,waiting_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], keep[10], temp[10];
    float avg_wt;//average waiting time, average turnaround time
    y = n;//temporary storage
    //details of every process
    for (i = 0; i < n; i++)
    {
        arrival_time[i]=proc[i].arrivalTime;
        temp[i]=i;
        burst_time[i]=proc[i].burstTime;
        keep[i] = burst_time[i]; // keeping track of burst time in a temporary array
    }
    printf("**RR**\nEnter the time quantum for the process: ");
    scanf("%d", &time_quantum);

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrival_time[j] > arrival_time[j + 1])
            {
                int temp1 = arrival_time[j];//swapping all the parameters
                int temp2 = burst_time[j];
                int temp3 = temp[j];
                arrival_time[j]=arrival_time[j+1];
                burst_time[j]=burst_time[j+1];
                temp[j] = temp[j+1];
                arrival_time[j+1]=temp1;
                burst_time[j+1]=temp2;
                temp[j+1]=temp3;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        keep[i] = burst_time[i]; // keeping track of burst time in a temporary array
    }

    //table obtained from gantt chart
    printf("\nProcesses \t\t Burst Time \t\t Turnaround Time \t\t Waiting Time ");
    total=0; i=0;
    while(y != 0)
    {
        if(keep[i]==0)
        {
            i++;
            if (i == n) i = 0;
            continue;
        }
        else if (keep[i] <= time_quantum && keep[i] > 0)
        {
            total = total + keep[i];
            keep[i] = 0;
            y--;//decrement the number of processes
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", temp[i] + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
            waiting_time = waiting_time + total - arrival_time[i] - burst_time[i];
            turnaround_time = turnaround_time + total - arrival_time[i];
            i++;
        }
        else
        {
            keep[i] = keep[i] - time_quantum;
            total = total + time_quantum;
            i++;
        }
        if (i == n) i = 0;
    }
    avg_wt = waiting_time * 1.0 / n;
    printf("\nAverage Waiting Time: %f\n\n", avg_wt);
}

// Driver code
void main()
{
    Process proc[] = {{1, 6, 2}, {2, 2, 5}, {3, 8, 1}, {4, 3, 0}, {5, 4, 4}};
    int n = sizeof(proc) / sizeof(proc[0]);
    SRTF(proc,n); SJF(proc,n); RR(proc,n); FCFS(proc,n);
}

/*

Acknowledgements :
Arjun Nambisan
Chirag Rao
Kumar Aditya
Ratan Kumar

*/
