//���ֺͣ�ȫ���� 
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
	{//���������ں��棬��Ϊ�п���x<0ʱ��s�պõ���0 
		return ;
	}

	//��ѡ��
	b[l]=a[x];
	f(s-a[x],x-1,l+1);
	b[l]=0;
	//��ѡ�� 
	f(s,x-1,l);

}

int main()
{

	int b=19;
	f(b,5,0);
			
} 
