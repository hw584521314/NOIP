//ջ 
#include<stdio.h>

int a[10]={0};
int head=0;
void push(int value)
{
	if(head>=10)
	{
		printf("full\n");
		return ;
	}
	a[head++]=value;
} 

int pop()
{
	if(head==0)
	{
		printf("empty\n");return -1;
	}
	return a[--head];
}

int length()
{
	return head;
}

int get()
{
	if(head==0)
	{
		printf("empty\n");return -1;
	}
	return a[head-1];
}


int main()
{
	for(int i=100;i<110;i++)
	{
		push(i);	
	} 
	int l=length();
	for(int i=0;i<l;i++)
	{
		printf("%d,",pop());
	}
}
 

