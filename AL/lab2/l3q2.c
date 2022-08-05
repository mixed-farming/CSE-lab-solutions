#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_string_match(char arr[],char subarr[])
{
	int i,j,m,n,count,flag=1,c=0;
	n=strlen(arr);
	m=strlen(subarr);

	if(m>n)
	{
		printf("Enter valid pattern string !");
	}

	for(i=0;i<n-m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(subarr[j]==arr[i])
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
		}
	}

	if(flag==1)
	{
		printf("Substring found");
	}
	else 
	{
		printf("substring not found");
	}
	return count;
}

int main()
{
	char arr[20],subarr[20];
	printf("Enter a text string : ");
	scanf("%s",arr);
	printf("Enter a pattern string : ");
	scanf("%s",subarr);
	int opcount = check_string_match(arr,subarr);
	printf("Opcount = %d",opcount);
}