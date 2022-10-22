%{
	#include<stdio.h>
	int num, r, digit=0, count=0, pcount=0, i;
	char a[20];
%}

DIGIT [0-9]
%%
{DIGIT}+ { 
        num=atoi(yytext);

		while(num>0)
		{
			r=num%16;
			digit='0'+r;//converting to equivalent ascii
			if(digit>'9')
			digit+=7;//wrt ascii table : 56->8, 57->9...65->A, 66->B
			a[count++]=digit;
			num=num/16;
		}

        if(count==pcount)
        printf("0");//corner case

		for(i=count-1;i>=pcount;--i)
        {
            printf("%c", a[i]);
        }
				
		pcount=count;//update base index of array for new number conversion
        printf("\nEnter decimal number : ");//for converting more numbers
		}
%%

int yywrap()
{}


int main()
{
    printf("Enter decimal number : \n");
	yylex();
	return 0;
}	
