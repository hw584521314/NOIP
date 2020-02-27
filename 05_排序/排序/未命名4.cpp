//¶ş·Ö²éÕÒ
#include<stdio.h>
int a[10]={2,6,9,12,15,23,44,45,51,55};
int b;

int f(int left,int right)
{
	if(left>right)
	{
		return -1;
	}
	int temp=(left+right)/2;
	if(a[temp]==b)
	{
		return temp;
	}
	else if(a[temp]>b)
	{
		return f(left,temp-1);
	}
	else
	{
		return f(temp+1,right);
	}
}

int main() 
{
	b=45;
	printf("%d",f(0,9));
}
