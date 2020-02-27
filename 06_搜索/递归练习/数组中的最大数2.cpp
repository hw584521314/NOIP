//求数组中的最大数 2
#include<stdio.h>


int a[8]={8,5,11,7,9,4,2,6};
int f(int x)
{
	if(x==7)
	{
		return a[7];
	}
	if(a[x]>f(x+1))
	{
		return a[x];
	}
	else
	{
		return f(x+1);
	}
}

int main()
{
	int b;
	b=f(0);
	printf("%d",b);
	return 0;
}
