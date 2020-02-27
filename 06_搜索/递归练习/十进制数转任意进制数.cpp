//十进制数转任意进制数 
#include<stdio.h>
char b[]="0123456789abcdef";
void f(int x,int j)
{
	if(x==0)
	{
		return ;
	}
	f(x/j,j);
	int a=x%j;
	printf("%c",b[a]);
	
}


int main()
{
	f(59,16); 
} 
