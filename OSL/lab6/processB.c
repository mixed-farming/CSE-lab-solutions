#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_message
{
    long int message_type;
    int num;
};

int is_palindrome(int t)
{
    char arr[100];
    sprintf(arr,"%d",t);//conversion from int to string
    int n=strlen(arr);//length of the string
    // while (t > 0)
    // {
    //     int dig = t % 10;
    //     t /= 10;
    //     arr[n++] = dig;
    // }
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int running = 1;
    int msgid;
    struct my_message data;
    long int msg_to_receive = 0;
    msgid = msgget((key_t)27, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("msgget failed");
        exit(1);
    }
    while (running)
    {
        if (msgrcv(msgid, (void *)&data, sizeof(int), msg_to_receive, 0) == -1)
        {
            perror("msgrcv failed");
            exit(1);
        }
        if (data.num == -1)
        {
            running = 0;
        }
        else if (is_palindrome(data.num))
        {
            printf("%d is a palindrome\n", data.num);
        }
        else
        {
            printf("%d is not a palindrome\n", data.num);
        }
    }
    if (msgctl(msgid, IPC_RMID, 0) == -1)//remove the message queue
    {
        perror("msgctl failed");
        exit(1);
    }
    exit(0);
}
