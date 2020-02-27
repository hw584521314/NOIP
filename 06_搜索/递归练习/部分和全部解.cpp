//部分和，全部解 
#include<stdio.h>
int a[6]={5,4,2,9,11,8};
int b[6]={0}; 

void f(int s,int x,int l)
{
	if(s<0) 
	{
		return;
	}
	else if(s==0)
	{	
		for(int i=0;i<l;i++)
		{
			printf("%d,",b[i]);
		}
		printf("\n");	
		return ;
	}
	else if(x<0)
	{//这个必须放在后面，因为有可能x<0时，s刚好等于0 
		return ;
	}

	//若选择
	b[l]=a[x];
	f(s-a[x],x-1,l+1);
	b[l]=0;
	//不选择 
	f(s,x-1,l);

}

int main()
{

	int b=19;
	f(b,5,0);
			
} 
