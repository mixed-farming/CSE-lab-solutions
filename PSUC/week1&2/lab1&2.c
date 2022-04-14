                             Lab no: 1 – SIMPLE C PROGRAMS

Q1. Write a C program to add two integers a and b read through the keyboard. Display the result using third variable sum.
Program:
/* Computing the sum of two numbers */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    int a,b,sum;
    printf("Enter two integers : ");
    scanf("%d %d",&a,&b);
    sum = (a+b); // sum
    printf("\nThe sum of %d and %d is %d\n",a,b,sum);
    return 0;
}
Output:
 
Q2. Write a C program to find the sum, difference, product and quotient of 2 numbers.
Program:
/* Finding the sum, difference, product and quotient of 2 numbers */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    double a,b;
    double sum,difference,product,quotient;
    printf("Enter the first number : ");
    scanf("%lf",&a);
    printf("Enter the second number (non-zero number) : ");
    scanf("%lf",&b);
    sum = a + b; 
    difference = a - b;
    product = a * b;
    quotient = a / b ;
    printf("\nSum = %lf \nDifference = %lf \nProduct = %lf \nQuotient = %lf\n",sum,difference,product,quotient);
    return 0;
}




Output:
 


Q3. Write a C program to print the ASCII value of a character.
Program:
/* Printing the ASCII value of a character */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    char letter;
    printf("Enter the character : ");
    scanf("%c",&letter);
    printf("\nThe ASCII value of %c is %d\n",letter,letter);
    return 0;
}
Output:
 


Q4. Write a C program to display the size of the data type int, char, float, double, long int and long double using size of ( ) operator. 
Program:
/* Getting the size of different data types */ 
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");

    printf("size of int = %d bytes\n",sizeof(int));
    printf("size of char = %d bytes\n",sizeof(char));
    printf("size of float = %d bytes\n",sizeof(float));
    printf("size of double = %d bytes\n",sizeof(double));
    printf("size of long int = %d bytes\n",sizeof(long int));
    printf("size of long double = %d bytes\n",sizeof(long double));

    return 0;
}
Output:
 


Q5. Input P, N and R to compute simple and compound interest. [Hint: SI = PNR/100, CI = P(1+R/100)N -P] 
Program:
/* computing simple and compound interest */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    double principal,time,rate,simple_interest,compound_interest;
    printf("Enter principal amount(in Rs) : ");
    scanf("%lf",&principal);
    printf("Enter the term period(in years) : ");
    scanf("%lf",&time);
    printf("Enter the rate of interest(in percentage) : ");
    scanf("%lf",&rate);
    // computation
    simple_interest = (principal*time*rate)/100;
    compound_interest = principal*pow((1+rate/100),time) - principal;
    printf("Simple interest = %lf \nCompound interest = %lf ",simple_interest,compound_interest);
    return 0;
}
Output:
 
Q6. Input radius to find the volume and surface area of a sphere. [Hint: volume = (4πr3 )/3, Area=4πr2 ] 
Program:
/* Finding volume and surface area of a sphere */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265 //defining the value of irrational constant π (pi)

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");

    double radius,volume,surface_area;
    printf("Enter the radius of sphere : ");
    scanf("%lf",&radius);
    //computation
    volume = (4*PI*radius*radius*radius)/3;
    surface_area = 4*PI*radius*radius;

    printf("\nThe volume of the sphere is %lf\n",volume);
    printf("\nThe surface area of the sphere is %lf\n",surface_area);

    return 0;
}

Output:
 


Q7. Convert the given temperature in Fahrenheit to Centigrade. [Hint: C=5/9(F-32)] 
Program:
/* Conversion from Fahrenheit to Centigrade */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");

    float fahrenheit,centigrade;
    printf("Enter the temperature in Fahrenheit : ");
    scanf("%f",&fahrenheit);

    //conversion
    centigrade = 5*(fahrenheit-32)/9;

    printf("\nThe temperature in Centigrade = %f ",centigrade);
    return 0;
}
Output:
 


Q8. Write a C program to evaluate the following expression for the values a = 30, b=10, c=5, d=15. (i ) (a + b) * c / d (ii) ((a + b) * c) / d (iii) a + (b * c) / d (iv) (a + b) * (c / d)
Program:
/* Evaluation */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");

    int a=30,b=10,c=5,d=15;
    printf("(a + b) * c / d = %d \n((a + b) * c ) / d = %d \na + (b * c) / d = %d \n(a + b) * (c / d) = %d\n",(a + b)*c/d, ((a + b)*c)/d, a+ (b*c)/d, (a + b)*(c/d));
    return 0;
}
Output:
 






**********
Lab no: 2 – BRANCHING CONTROLSTRUCTURES


Write C programs to do the following:
 
Q1. Check whether the given number is odd or even.
Program:
/* checking whether a number is odd or even */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    
    //checking remainder when divided by 2
    if (n%2==1)
    {
        printf("\n%d is an odd number.\n",n);
    }
    else
    {
        printf("\n%d is an even number.\n",n);
    }
    return 0;
}
Output:
 


Q2. Find the largest among given 3 numbers.
Program:
/* finding the largest number */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    int a,b,c;
    printf("Enter 3 numbers : ");
    scanf("%d %d %d",&a,&b,&c);

    if (a>b)
    {
        if (a>c)
        {
            printf("\n%d is the largest number.\n",a);
        }
        else
        {
            printf("\n%d is the largest number.\n",c);
        }
    }
    else
    {
        if (b>c)
        {
            printf("\n%d is the largest number.\n",b);
        }
        else
        {
            printf("\n%d is the largest number.\n",c);
        }
    }
    return 0;
}
Output:
 


Q3. Swap two numbers without using third variable. 
Program:
/* swapping two numbers witjout using 3rd variable */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    int a,b;
    printf("Enter first number : ");
    scanf("%d",&a);

    printf("\nEnter second number : ");
    scanf("%d",&b);

    a=a+b;// a becomes (a+b) 
    b=a-b;//b becomes a 
    a=a-b;//a becomes b 

    printf("\nFirst number after interchanging : %d\n",a);
    printf("\nSecond number after interchanging : %d\n",b);
    return 0;
}
Output:
 


Q4. Compute all the roots of a quadratic equation using switch case statement. [Hint: x = (-b +/- sqrt(b2 -4ac))/2a] 
Program:
/* getting the roots of a quadratic equation */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    double a,b,c,x,y,real,imaginary;
    printf("The quadratic equation is of the form ax^2+bx+c=0\n\n");// standard form of a quadratic equation

    printf("Enter a : ");
    scanf("%lf",&a);

    printf("Enter b : ");
    scanf("%lf",&b);

    printf("Enter c : ");
    scanf("%lf",&c);

    double disc = (b*b)-(4*a*c);//disc - discriminant
    int k;

    if(a!=0)
    {
        if (disc > 0)
        {
            k=1;
        }
        if (disc == 0)
        {
            k=2;
        }
        if (disc < 0)
        {
            k=3;
        }

        switch (k)
        {
        case 1:
            printf("\nRoots are real and distinct.\n");
            x = ((-b) + sqrt((b*b) - (4*a*c)))/(2*a);//1st root
            y = ((-b) - sqrt((b*b) - (4*a*c)))/(2*a);//2nd root
            printf("\nThe two roots of the quadratic equation are x = %lf and y = %lf\n",x,y);
            break;

        case 2:
            printf("\nRoots are real & equal.\n");
            x = -b / (2*a);
            printf("\nThe two roots of the quadratic equation are %lf and %lf\n",x,x);
            break;

        case 3:
            printf("\nRoots are imaginary.\n");
	        real = -b / (2*a) ;
	        imaginary = (sqrt (-1*disc)) / (2*a);
	        printf("\nThe two roots of the quadratic equation are x = %f + i(%f) and y = %f - i(%f)\n",real,imaginary,real,imaginary);
        }
    }

    else
    {
        printf("\nIts a linear equation.\n");// as the co-efficient of 'a' is zero.
    }
    return 0;
}
Output:
 

Q5. Write a program that will read the value of x and evaluate the following function
 
Use else if statements & Print the result (‘Y’ value). 
Program:
/* signum function */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    int n,result;
    printf("Enter a number : ");
    scanf("%d",&n);

    if (n>0)
    {
        result = 1;//when the number is greater than zero
    }
    else if (n<0)
    {
        result = -1;//when the number is less than zero
    }
    else
    {
        result = 0;//when the number is equal to zero
    }

    printf("\nThe result of the function = %d\n",result);
        return 0;
}
Output:
 


Q6. Find the smallest among three numbers using conditional operator.
Program:
/* finding the smallest of 3 numbers using conditional operator */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Name : MANOJ M MALLYA\n\n");
    int a,b,c,small;
    printf("Enter three numbers : ");//getting the 3 numbers
    scanf("%d %d %d",&a,&b,&c);

    small = (a < b)? ((a < c)? a : c ) : ((b < c)? b : c);//getting the smallest number
    printf("\nThe smallest number is %d\n",small);//printing the smallest number
    return 0;
}
Output:
 

**********
