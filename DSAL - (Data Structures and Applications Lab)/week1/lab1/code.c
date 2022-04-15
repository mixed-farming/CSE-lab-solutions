DSA Lab - 1


Example 1: 

Write a program to read n names of different sports and store them using array pointers. Use
dynamic memory allocation and deallocation functions. The program should display all the
names and deallocate the dynamic memory at the end of the program.

Code :
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
int i,n;
char *sports[10];
char str[100];
printf("\n enter the number of sports \n");
scanf("%d", &n);
printf("\nenter the names of sports:\n");
for (i = 0; i < n; i++)
{
scanf("%s", str);
//allocating memory equal to the length of string + 1
//Last 1 byte to accommodate the ‘\0’
sports[i] = (char*) calloc(strlen(str)+1, sizeof(char));
strcpy(sports[i],str);
}
printf("\nGiven list of sports: \n");
for (i = 0; i < n; i++)
printf("%s\n", sports[i]);
//Deallocate the dynamic memory
for (i = 0; i < n; i++)
free(sports[i]);
return 0;
}


Example 2 : 

Write a C program to implement a ragged array dynamically.

Code :
#include<stdio.h>
#include<stdlib.h>
int main(){
int rowNum, colNum, i, j;
int **table;
printf("\n enter the number of rows \n");
scanf("%d", &rowNum);
table = (int **) calloc(rowNum+1, sizeof(int *));
for (i = 0; i < rowNum; i++) /* this will tell which row we are in */
{
printf("enter size of %d row", i+1);
scanf("%d", &colNum);
table[i] = (int *) calloc(colNum+1, sizeof(int));
printf("\n enter %d row elements ", i+1);
for (j = 1; j <= colNum; j++)
{
scanf("%d", &table[i][j]);
}
table[i][0] = colNum;
printf("size of row number [%d] = %d", i+1, table[i][0]);
}
table[i] = NULL;
for (i = 0; i < rowNum; i++) /* this will tell which row we are in */
{
printf("displaying %d row elements\n", i+1);
for (j = 0; j <= *table[i]; j++)
{printf("%5d", table[i][j]);
}
printf("\n");
}
//freeup the memory
for (i = 0; i < rowNum; i++) {
free(table[i]);
}
free(table);
return 0;
}


Questions for LAB -1

1) Write a function Smallest to find the smallest element in an array using pointer. Create
a dynamically allocated array and read the values from keyboard in main. Display the
result in the main function.

Code : 

#include <stdio.h>
#include <stdlib.h>
void Smallest(int n,int *ptr);
int main()
{
 int n,i,*ptr,*arr,small;
 printf("Enter the number of elements : ");
 scanf("%d",&n);
 arr = (int *)calloc (n,sizeof(int));
 if(arr==NULL)
 {
 printf("\nMemory not allocated.\n");
 }
 else
 {
 printf("\nMemory has been successfully allocated using calloc.\n\nPopulate the array : \n");
 }
 for(i=0; i<n; i++)
 {
 scanf("%d",&arr[i]);
 }
 ptr = arr;
 Smallest(n,ptr);
 small = *ptr;
 printf("\nThe smallest number in the array is %d.\n",small);
 return 0;
}
void Smallest(int n,int *ptr)
{
 int *p;
 p = ptr;
 for(int j=1; j<n; j++)
 {
 if(ptr[j]<*p)
 {
 *p = ptr[j];
 }
 }
 *ptr = *p ;
}


2) Implement a C program to read, display and to find the product of two matrices using
functions with suitable parameters. Note that the matrices should be created using
dynamic memory allocation functions and the elements are accessed using array
dereferencing.

Code : 

#include <stdio.h>
#include <stdlib.h>
int main()
{
 int i, j, m, n, p, q;
 int **a,**b,**c;
 printf("Enter dimension for a \n");
 scanf("%d %d",&m,&n);
 a = (int **) calloc(m,sizeof(int *));
 for(i=0; i<m; i++)
 {
 a[i] = (int *)calloc(n,sizeof(int));
 }
 printf("\nEnter dimension for b \n");
 scanf("%d %d", &p,&q);
 b = (int **) calloc(p,sizeof(int *));
 for(i=0; i<p; i++)
 {
 b[i] = (int *)calloc(q,sizeof(int));
 }
 if(a==NULL||b==NULL)
 {
 printf("Memory allocation failed.");
 }
 if(n!=p)
 {
 printf("\nNOT MULTIPLICABLE\n");
 exit(0); // Terminate the execution
 }
 //else we can multiply the matrices and the order of the resultant matrix would be m x q
 c = (int **) calloc(m,sizeof(int *));
 for(i=0; i<m; i++)
 {
 c[i] = (int *)calloc(q,sizeof(int));
 }
 printf("Memory has been successfully allocated");
 printf("\nEnter elements for 1st matrix : \n");
 for (i=0; i<m; i++)
 {
 for(j=0; j<n; j++)
 {
 scanf("%d",&a[i][j]);
 }
 }
 printf("\nEnter elements for 2nd matrix : \n");
 for(i=0; i<p; i++)
 {
 for(j=0; j<q; j++)
 {
 scanf("%d",&b[i][j]);
 }
 }
 //multiplication
 for(i=0; i<m; i++)
 for(j=0; j<q; j++)
 {
 *(*(c+i)+j) = 0;
 for(int k=0; k<n; k++)
 {
 *(*(c+i)+j) = *(*(c+i)+j) + *(*(a+i)+k) * *(*(b+k)+j);
 }
 }
 printf("\nThe product matrix is : \n");
 for(i=0; i<m; i++)
 {
 for(j=0; j<q; j++)
 {
 printf("%d\t",*(*(c+i)+j));
 }
 printf("\n");
 }
 return 0;
}


3) Samuel wants to store the data of his employees, which includes the following fields:
(i) Name of the employee (ii) Date of birth which is a collection of {day, month, year}
(iii) Address which is a collection of {house number, zip code and state}. Write a 'C'
program to read and display the data of N employees using pointers to array of
structures.

Code : 

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
 int date,month,year;
}DOB;
typedef struct
{
 int house_no;
 long zipcode;
 char state[20];
}ADRS;
typedef struct
{
 char name[20];
 DOB dob;
 ADRS address;
}EMPLOYEE;
int main()
{
 EMPLOYEE emp[10];
 EMPLOYEE *ptr = emp;
 int N;
 printf("Enter the number of employees : ");
 scanf("%d",&N);
 for(int i=0; i<N; i++)
 {
 printf("Enter the name of employee %d\n",i+1);
 scanf("%s",(ptr+i)->name);
 printf("Enter the date of birth of employee %d in date,month,year format\n",i+1);
 scanf("%d%d%d",&((ptr+i)->dob.date),&((ptr+i)->dob.month),&((ptr+i)->dob.year));
 printf("Enter the address of employee %d in house number, zipcode, state format\n",i+1);
 scanf("%d %ld %s",&((ptr+i)->address.house_no),&((ptr+i)->address.zipcode),(ptr+i)-
>address.state);
 }
 printf("\n\nThe employee details are : \n");
 for(int i=0; i<N; i++)
 {
 printf("\nThe name of employee %d is %s\n",i+1,(ptr+i)->name);
 printf("The date of birth of employee %d in date-month-year format is %d-%d-%d\n",i+1,
(ptr+i)->dob.date,(ptr+i)->dob.month,(ptr+i)->dob.year);
 printf("The address of employee %d : \nHouse number - %d \nZipcode - %ld \nState - %s\
n",i+1,((ptr+i)->address.house_no),((ptr+i)->address.zipcode),((ptr+i)->address.state));
 }
 return 0;
}
