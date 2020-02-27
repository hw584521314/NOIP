//部分和有无解 
#include<stdio.h>
int a[6]={5,4,2,9,11,8};
int f(int s,int x)
{
	if(s<0||x<0)
	{
		return 0;
	}
	if(s==0)
	{
		return 1;
	}
	//若选择
	if(f(s-a[x],x-1)||f(s,x-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int main()
{

	int b=33;
	if(f(b,5))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}		
} 
