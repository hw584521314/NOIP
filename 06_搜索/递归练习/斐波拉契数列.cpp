//��ӡ쳲��������е�n��-δ���������汾 
#include<stdio.h>

int f(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	return f(n-1)+f(n-2);
}

int main()
{
	int a;
	a=f(6);
	printf("%d",a);
	return 0;
} 
