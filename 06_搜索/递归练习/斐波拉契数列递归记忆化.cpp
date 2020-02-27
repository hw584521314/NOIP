#include<stdio.h>
int a[100];
int f(int n)
{
	if(a[n]!=0) return a[n];
	if(n==1||n==2)
	{
		return 1;
	}
	a[n]=f(n-1)+f(n-2);
	return a[n];
}


int main()
{
	int a;
	a=f(10);
	return 0;	
} 
