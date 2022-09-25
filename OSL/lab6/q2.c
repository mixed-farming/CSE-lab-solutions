#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    int stat, shmid;//shared memory id
    void *mem = (void *)0;
    char ch, *alpha;
    shmid = shmget((key_t)27, sizeof(char), 0666 | IPC_CREAT);//create shared memory 
    if (shmid == -1)
    {
        printf("shmget() failed\n");
        exit(1);
    }
    mem = shmat(shmid, (void *)0, 0);//attach shared memory to address space of parent process, (void *)0 == NULL
    if (mem == (void *)-1)
    {
        printf("shmat() failed\n");
        exit(1);
    }
    printf("Enter an alphabet: ");
    scanf("%c", &ch);
    alpha = (char *)mem;
    alpha[0] = ch;
    pid_t pid = fork();
    switch (pid)
    {
    case -1:
        printf("ERROR\n");
        break;
    case 0:
        if (alpha[0] == 'z')
        {
            alpha[0] = 'a';
        }
        else if (alpha[0] == 'Z')
        {
            alpha[0] = 'A';
        }
        else
        {
            alpha[0] = alpha[0] + 1; 
        }
        printf("Child process executed\n");
        exit(0);
    default:
        wait(&stat);
        printf("Next alphabet: %c\n", alpha[0]);
    }
    if (shmdt(mem) == -1)//detach shared memory from parent process
    {
        printf("shmdt() failed\n");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1)//delete shared memory segment
    {
        printf("shmctl() failed\n");
        exit(1);
    }

    exit(0);
}
