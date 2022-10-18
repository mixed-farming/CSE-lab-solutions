%{
	int vow_count=0;
	int const_count =0;
%}

%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}//operates like else if ladder
%%

int main()
{
	printf("Enter the string of vowels and consonents: ");
	yylex();
	printf("Number of vowels are: %d\n", vow_count);
	printf("Number of consonants are: %d\n", const_count);
	return 0;
}

//
int yywrap(){
    return 1;//optional
}
