//倒序输出正整数 
#include<stdio.h>

void f(int m)
{
	if(m==0)
	{
		return;
	}
	printf("%d",m%10);
	f(m/10);
	
}

int main()
{
	f(123);
}
