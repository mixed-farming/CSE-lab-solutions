main ()
{
 	int a,d[2],e,i,j;
	char b,c;
	a=5;
	e=2;
	if(a==e)
	{
		a=6;
	}
	else
    {
		a=7;
	}//if else - works

	if(a==0)
	{
		a=1;
	}
 	else if(a==1)
	{
		a=2;
	}
	else if(a==2)
	{
		a=3;
	}
	else
	{
		a=4;
	}//else if ladder - works

 	for(i=0;i<10;i=i+1)
	{
		a=5;
	}//for - works

	for(i=0;i<10;i++)
	{
		a=5;
	}//for loop with increment operator - works

	for(i=10;i>0;i--)
	{
		a=5;
	}//for loop with decrement operator - works

	while(a<=10)
	{
		a=a+1;
	}//while - works

	for(i=0;i<10;i=i+1)
	{
		for(j=0;j<10;j=j+1)
		{
			a=5;
		}
	}//nested for - works

	while(a<=10)
	{
		while(a<=10)
		{
			a=a+1;
		}
		a=a+1;
	}//nested while - works

	if(a<10)
	{
		if(a<5)
		{
			a=a+5;
		}
	}//nested if - works

	
}