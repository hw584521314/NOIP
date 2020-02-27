//双汉诺塔移动明细
/*
难点在于每次移动两个，但这相同宽度的两个铁块他们不停地处于栈状态：先进后出
因此这里使用一个数组b来跟踪是否颠倒 
*/ 
#include<stdio.h>
int count=0;
int b[5]={0};
void f(int n,char from ,char to, char buffer)
{
	if(n==2)
	{	
		if(b[n/2]==0)
		{
			printf("%d:%c->%c\n",n-1,from,to);
			printf("%d:%c->%c\n",n,from,to);
			b[n/2]=1;	
		} 
		else
		{
			printf("%d:%c->%c\n",n,from,to);
			printf("%d:%c->%c\n",n-1,from,to);
			b[n/2]=0;
		}
		return;
	}

	f(n-2,from,buffer,to);//首先把前面n-1个从from 移到buffer
	if(b[n/2]==0)
	{
		printf("%d:%c->%c\n",n-1,from,to);
		printf("%d:%c->%c\n",n,from,to);
		b[n/2]=1;	
	} 
	else
	{
		printf("%d:%c->%c\n",n,from,to);
		printf("%d:%c->%c\n",n-1,from,to);
		b[n/2]=0;
	}
		
	f(n-2,buffer,to,from); //最后把之前的n-1个从buffer移到to 		

}

int main()
{
	f(6,'a','c','b');
	printf("\n%d",count);
	return 0;
}


