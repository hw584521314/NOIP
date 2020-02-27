//汉诺塔移动明细 
#include<stdio.h>
int count=0;
void f(int n,char from ,char to, char buffer)
{
	if(n==1)
	{
		printf("%d:%c->%c\n",1,from,to);
		count++;
		return;
	}
	f(n-1,from,buffer,to);//首先把前面n-1个从from 移到buffer 
	printf("%d:%c->%c\n",n,from,to);//然后把当前这个从from移到to 
	count++;
	f(n-1,buffer,to,from); //最后把之前的n-1个从buffer移到to 
	
}

int main()
{
	f(4,'a','c','b');
	printf("\n%d",count);
	return 0;
}


