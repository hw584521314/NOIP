//部分和一个解 
#include<stdio.h>
int a[6]={5,4,2,9,11,8};
int f(int s,int x)
{
	if(s<0)
	{
		return 0;
	}
	if(s==0)
	{	
		printf("\n");	
		return 1;
	}
	if(x<0)
	{
		return 0;
	}
	//若选择
	int c=f(s-a[x],x-1);
	if(c==1)
	{
		printf("%d,",a[x]);
		return 1;		
	} 
	//不选择 
	int b=f(s,x-1);

	if(c||b)
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

	int b=23;
	if(f(b,5))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}		
} 
