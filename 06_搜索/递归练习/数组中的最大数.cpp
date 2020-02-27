//求数组中的最大数 
#include<stdio.h>


int a[8]={8,5,11,7,9,4,2,6};
int f(int x)
{
	if(x==0)
	{
		return a[0];
	}
	if(a[x]>f(x-1))
	{
		return a[x];
	}
	else
	{
		return f(x-1);
	}
}

int main()
{
	int b;
	b=f(7);
	printf("%d",b);
	return 0;
}
