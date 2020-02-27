//小明外婆家 递归思路实现 
#include<stdio.h>
int a[]={1,2,3};
int b[]={4,5};
int c[2]={0};
void f(int n)
{
	if(n==2)
	{
		for(int i=0;i<2;i++)
		{
			c[0]=b[i];
			f(1);
		} 
		return ;
	}
	if(n==1)
	{
		for(int i=0;i<3;i++)
		{
			printf("%d,%d\n",c[0],a[i]);
		} 	
		return;
	}	
} 

int main()
{
	f(2);
}
