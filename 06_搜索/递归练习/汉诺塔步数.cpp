//汉诺塔步数 
#include<stdio.h>

int f(int n)
{
	int count=0; 
	if(n==1)
	{//这里应该理解为当只有一块需要移动时 
		return 1;
	}
	count+=f(n-1);//f(n-1)c移到b
	count+=1;//最后一块a移到c
	count+=f(n-1);//f(n-1)从b移到c 
	return count;
}

int main()
{
	int a;
	a=f(4);
	printf("%d",a);
}
