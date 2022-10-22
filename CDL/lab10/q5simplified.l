%{
	int num;
%}

DIGIT [0-9]
%%
{DIGIT}+ {
    num=atoi(yytext);
    printf("Hexadecimal equivalent : %x",num);
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
