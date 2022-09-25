#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_message
{
    long int message_type;
    int num;
};

int main()
{
    int running = 1;
    int msgid;//message queue identifier
    struct my_message data;
    msgid = msgget((key_t)27, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("msgget failed");
        exit(1);
    }
    while (running)
    {
        printf("Enter a number : ");
        int n;
        scanf("%d", &n);
        data.message_type = 1;
        data.num = n;
        if (msgsnd(msgid, (void *)&data, sizeof(int), 0) == -1)
        {
            perror("msgsnd failed");
            exit(1);
        }
        if (n == -1)
        {
            running = 0;
        }
    }
    exit(0);
}
