%{
    int a=0,b=0,c=0,d=0;
%}

%%
([a-zA-Z0-9])* {a++; b+=yyleng;}//number of words, number of characters
([ ])+ c++; //number of blanks
\n d++;//number of lines
%%

int main()
{
    printf("Enter the input string : ");

	yylex();
	
	printf("\nNumber of words=%d",a);
	printf("\nNumber of characters=%d",b);
	printf("\nNumber of blanks=%d",c);
	printf("\nNumber of lines=%d\n",d);
	
}
