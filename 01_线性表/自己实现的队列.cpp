//�Լ�ʵ��һ������ 
#include<stdio.h>
/*
��head==tailʱ��Ϊ����Ϊ��
��head==(tail+1)%Capʱ��Ϊ������
����ʱ��tail��ȡ��ʱ��head
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

 
