#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen("input.c","r");
	if(fa == NULL){
		printf("Cannot open file!\n");
		exit(0);
	}
	fb = fopen("output.c","w");

	char c='"';
	int flag=1;

	ca = getc(fa);
	while(ca != EOF)
	{
		if(ca==c)
			flag=flag*(-1);

		if((ca == ' ' || ca == '\t') && flag==1)
		{
			putc(' ',fb);
			while(ca == ' ' || ca == '\t')
				ca = getc(fa);
		}
		if(ca == '/')
		{
			cb = getc(fa);
			if(cb == '/')
			{
				while(ca != '\n')
					ca = getc(fa);
			}
			else if(cb == '*')
			{
				do
				{
					while(ca != '*')
						ca = getc(fa);
					ca = getc(fa);
				} while(ca != '/');
			}
			else
			{
				putc(ca, fb);
				putc(cb, fb);
			}
		}
		else putc(ca, fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}