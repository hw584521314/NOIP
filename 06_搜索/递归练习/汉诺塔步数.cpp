//��ŵ������ 
#include<stdio.h>

int f(int n)
{
	int count=0; 
	if(n==1)
	{//����Ӧ�����Ϊ��ֻ��һ����Ҫ�ƶ�ʱ 
		return 1;
	}
	count+=f(n-1);//f(n-1)c�Ƶ�b
	count+=1;//���һ��a�Ƶ�c
	count+=f(n-1);//f(n-1)��b�Ƶ�c 
	return count;
}

int main()
{
	int a;
	a=f(4);
	printf("%d",a);
}
