//˫��ŵ���ƶ���ϸ
/*
�ѵ�����ÿ���ƶ�������������ͬ��ȵ������������ǲ�ͣ�ش���ջ״̬���Ƚ����
�������ʹ��һ������b�������Ƿ�ߵ� 
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

	f(n-2,from,buffer,to);//���Ȱ�ǰ��n-1����from �Ƶ�buffer
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
		
	f(n-2,buffer,to,from); //����֮ǰ��n-1����buffer�Ƶ�to 		

}

int main()
{
	f(6,'a','c','b');
	printf("\n%d",count);
	return 0;
}


