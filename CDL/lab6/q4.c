/*
after removing left recursion

S->(L)|a
L->SL'
L'->,SL'|ε

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[100];
int i=0;
void S();
void L();
void Ldash();

void invalid()
{
    //printf("String failed at %c\n", buf[i]); // to debug
    printf("*****FAILURE*****\n");
    exit(1);
} 

void valid()
{
    printf("*****SUCCESS*****\n");
    exit(1);
}

void S()
{
    if(buf[i]=='a')
    {
        i++;
        return;
    }
    else if(buf[i]=='(')
    {
        i++;
        L();
        if(buf[i]==')')
        {
            i++;
            return;
        }
        else
        {
            invalid();
        }
    }
    else
    {
        invalid();
    }
}

void L()
{
    S();
    Ldash();
}

void Ldash()
{
    if(buf[i]==',')
    {
        i++;
        S();
        Ldash();
    }
    //else Ldash->ε
}

int main()
{
    printf("Enter the input string : ");
    scanf("%s",buf);
    S();
    if(buf[i]=='$')
        valid();
    else 
    {
        invalid();
    }
    return 0;
}

//productions look like rules for tuples in python