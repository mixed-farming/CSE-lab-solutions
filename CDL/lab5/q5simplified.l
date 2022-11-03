%{
	int num;
%}

DIGIT [0-9]
%%
{DIGIT}+ {
    num=atoi(yytext);
    printf("Hexadecimal equivalent : %X",num);//%x for small cases of (10-15)
}
%%

int yywrap()
{}

int main()
{
    printf("Enter decimal number : ");
	yylex();
	return 0;
}	
