/*
after removing left recursion

S->aAcBe
A->bA'
A'->bA'|ε
B->d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[100];
int i=0;
void S();
void A();
void Adash();
void B();

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
        A();
        if(buf[i]=='c')
        {
            i++;
            B();
            if(buf[i]=='e')
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
    else
    {
        invalid();
    }
}

void A()
{
    if(buf[i]=='b')
    {
        i++;
        Adash();
    }
    else
    {
        invalid();
    }
}

void Adash()
{
    if(buf[i]=='b')
    {
        i++;
        Adash();
    }
    //else Adash->ε
}

void B()
{
    if(buf[i]=='d')
    {
        i++;
        return;
    }
    else
    {
        invalid();
    }
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

//productions are of the form ab+cde i.e. exactly 1a,1c,1d,1e and atleast 1b