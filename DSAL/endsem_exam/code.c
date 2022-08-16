/*Its just partial code with bugs. Come up with pull request if you fix it :)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Epassenger
{
    char name[100];
    long int phnum;
    char food;
} Epassenger;
typedef struct Cpassenger
{
    char name[100];
    long int phnum;
} Cpassenger;
typedef struct CCnode *ccptr;
typedef struct ECnode *ecptr;
typedef struct CCnode
{
    int vacant;
    int coachnum;
    Cpassenger p;
    ccptr nextc;
    ecptr nexte;
} CCnode;
typedef struct ECnode
{
    int vacant;
    int coachnum;
    Epassenger E;
    ecptr nexte;
    ccptr nextc;
} ECnode;
typedef struct engine *headptr;
typedef struct header
{
    char myname[100];
    long int reg_no;
    int cc;
    int ec;
    ecptr nexte;
    ccptr nextc;
} header;
void insertC(ccptr cp, headptr eng)
{
    ccptr temp;
    temp = (ccptr)malloc(sizeof(struct CCnode));
    printf("Enter name\n");
    char name[100];
    scanf("%s", name);
    printf("Enter mobile number\n");
    long int phnum;
    scanf("%ld", &phnum);
    strcpy((temp->p).name, name);
    (temp->p).phnum = phnum;
    printf("Enter the coach number\n");
    int cnum;
    scanf("%d", &cnum);
    temp->coachnum = cnum;
    temp->nextc = NULL;
    temp->nexte = NULL;
    if (eng->nextc == NULL)
    {
        eng->nextc = temp;
    }
    else
    {
        ccptr last;
        last = eng;
        while (last->ccptr != NULL)
        {
            last = last->nextc;
        }
        last->nextc = temp
    }
    temp->vacant--;
}
void insertE(ccptr cp3)
{
    ecptr temp;
    temp = (ecptr)malloc(sizeof(struct ECnode));
    printf("Enter name\n");
    char name[100];
    scanf("%s", name);
    printf("Enter mobile number\n");
    long int phnum;
    scanf("%ld", &phnum);
    char food;
printf("Enter V for vegetarian food choice and N for non-vegetarian food 
choice\n");
scanf("%c",&food);
strcpy((temp->p).name , name);
(temp->p).phnum = phnum;
(temp->p).food = food;
printf("Enter the coach number\n");
int cnum;
scanf("%d",&cnum);
temp->coachnum = cnum;
temp->nextc=NULL;
temp->nexte=NULL;
if(cp3->nexte == NULL){
        cp3->nexte = temp;
}
else{
        ecptr last;
        last = cp3;
        while (last->nexte != NULL)
        {
            last = last->nexte;
        }
        last->nexte = temp;
}
}
void display(headptr eng)
{
    ccptr temp1;
    ecptr temp2;
    temp1 = eng->nextc;
    while (temp1)
    {
        printf("Coach number is %d\n", temp1->coachnum);
        printf("Passenger name is %s\n", (temp1->p).name);
        printf("Passenger mobile number is %ld\n", (temp1->p).phnum);
        temp1 = temp1->nextc;
    }
    while (temp2)
    {
        printf("Coach number is %d\n", temp2->coachnum);
        printf("Passenger name is %s\n", (temp2->p).name);
        printf("Passenger mobile number is %ld\n", (temp2->p).phnum);
        printf("Passenger food choice is %c\n", (temp2->p).food);
        temp2 = temp2->nextc;
    }
}
void departureCC(header engine)
{
    if (vacant == 0)
        free(cc);
    ccptr temp;
    int count = 0;
    if (engine->ccptr)
        temp = engine->ccptr;
    ccptr t = temp;
    else
    {
        printf("No departure possible");
        return;
    }
    count++;
    while (temp->ccptr)
    {
        temp = engine->ccptr;
        count++;
    }
    if (temp->vacant == 1)
    {
        free(temp);
        count--;
        while (count--)
            t = t->ccptr;
        t->ccptr = NULL;
    }
    else
        temp->vacant++;
}
int main()
{
    headptr eng;
    eng->myname = "Manoj M Mallya";
    eng->reg_no = 200905130;
    eng->cc = 30;
    eng->ec = 10;
    ccptr cptr1;
    ccptr cptr2;
    ccptr cptr3;
    ecptr eptr1;
    ecptr eptr2;
    eng->nextc = cptr1;
    cptr1->nextc = cptr2;
    cptr2->nextc = cptr3;
    cptr3->nexte = eptr1;
    eptr1->nexte = eptr2;
    int choice;
    char coach_type;
    while (1)
    {
printf("Enter your choice: \n1.Booking \n2.Departure 
\n3.Charting\n4.Exit\n");
scanf("%d",&choice);
switch(choice){
        case 1:
printf("Choose coach type, enter E for EC coach and 
C for CC coach\n");
scanf("%c",&coach_type);
if(coach_type == 'C'){
                insertR(cptr1);
}
else{
}
case 2: printf("Enter your choice\n1.CC\n2.EC");
scanf("%d",&choice);
if()
}
    }
}
