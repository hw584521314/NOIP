//自己实现一个队列 
#include<stdio.h>
/*
当head==tail时认为队列为空
当head==(tail+1)%Cap时认为队列满
进入时到tail，取出时从head
*/
const int Cap=10;
int a[Cap]={0};
int head=0;
int tail=0;

void push(int value)
{
	if(head==(tail+1)%Cap)
	{
		printf("full\n");return;
	}	
	a[tail]=value;	
	tail=(tail+1)%Cap;
} 


int pop()
{
	if(head==tail)
	{
		printf("empty\n");return -1;
	}
	int temp=a[head];
	head=(head+1)%Cap;
	return temp;
}
int gethead()
{
	return a[head];
}
int gettail()
{
	return a[(tail-1+Cap)%Cap];
}

int length()
{
	return (tail-head+Cap)%Cap;
}

int main()
{
	push(4);
	push(5);
	push(6);
	push(7);
	
	printf("%d,",pop()	);
	printf("%d,",pop()	);
	printf("%d,",pop()	);
} 

 
