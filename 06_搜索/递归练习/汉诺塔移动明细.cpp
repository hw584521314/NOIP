//��ŵ���ƶ���ϸ 
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
	f(n-1,from,buffer,to);//���Ȱ�ǰ��n-1����from �Ƶ�buffer 
	printf("%d:%c->%c\n",n,from,to);//Ȼ��ѵ�ǰ�����from�Ƶ�to 
	count++;
	f(n-1,buffer,to,from); //����֮ǰ��n-1����buffer�Ƶ�to 
	
}

int main()
{
	f(4,'a','c','b');
	printf("\n%d",count);
	return 0;
}


