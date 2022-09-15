#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fa = fopen("in2.c","r");
	FILE *fb = fopen("out2.c","w+");
	if(!fa || !fb)
	{
		printf("File not found\n");
		exit(1);
	}
	char c;
	char buffer[100];
	buffer[0] = '\0';
	int i = 0;
	char *includeStr = "include", *defineStr = "define", *mainStr = "main";
	int mainFlag = 0;
	c=getc(fa);
	while(c != EOF)
	{
		if(c == '#' && mainFlag == 0)
		{
			while(c != ' ')
			{
				c = fgetc(fa);
				buffer[i++] = c;
			}
			buffer[i] = '\0';
			if(strstr(buffer, includeStr) != NULL || strstr(buffer, defineStr) != NULL)
			{
				while(c != '\n')
				{
					c = fgetc(fa);
				}
			}
			else
			{
				fputc('#', fb);
				for(int j=0;j<i;j++)
				{
					fputc(buffer[j], fb);
				}
				while(c != '\n')
				{
					c = fgetc(fa);
					fputc(c, fb);
				}
			}
			i = 0;
			buffer[0] = '\0';
		}
		else{
			if(mainFlag == 0)
			{
				buffer[i++] = c;
				buffer[i] = '\0';
				if(strstr(buffer, mainStr) != NULL)
				{
					mainFlag = 1;
				}
			}
			if(c == ' ' || c == '\n')
			{
				buffer[0] = '\0';
				i = 0;
			}
			fputc(c, fb);
		}

		c=fgetc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}