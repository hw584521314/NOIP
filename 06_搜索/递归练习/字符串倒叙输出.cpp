//¶ÁÈë×Ö·û´®µ¹ĞòÊä³ö 
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
