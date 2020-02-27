//计算x的n次方 
#include<stdio.h>

int f(int x,int n)
{
	if(n==1)
	{
		return x;
	}
	return x*f(x,n-1);
}

int main()
{
	int a;
	a=f(2,5);
	printf("%d",a);
	return 0;
}
