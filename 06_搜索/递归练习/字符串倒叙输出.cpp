//�����ַ���������� 
#include<stdio.h>
void f()
{
	char c;
	scanf("%c",&c);
	if(c=='!')
	{
		return;
	}
	f();
	printf("%c",c);	
}

int main()
{
	f();
	return 0;
}
