#include<stdio.h>

//int a[5]={1,2,3,4,5};
int a[5][5]={
{0,1,1,1,1},
{1,0,0,0,0},
{1,0,0,0,1},
{1,0,0,0,1},
{1,0,1,1,0}};
void SetColumn(int i)
{
	//���Ϊ1�����Ϊ2�����Ϊ2����Ϊ1 
	for(int k=0;k<5;k++)
	{
		if(a[k][i]==1) 
		{
			a[k][i]=2;	
		}else if(a[k][i]==2)
		{
			a[k][i]=1;
		}
	}
}
int stack[5]={0};
void f(int i,int l)
{

	//�Ե�ǰ�У�����ÿ�У����Ƿ���ĳһ����ֵ�������ֵ��˵�����ж�Ӧ�ĵ���Է��� 
	for(int j=0;j<5;j++)
	{
		if(j==i) continue;
		if(a[i][j]==1)
		{
			//�ѵ�ǰ���Ӧ��·���� �������������ߵ�����ػ� 
			SetColumn(i);
			stack[l]=i;
			f(j,l+1);
			//���· 
			SetColumn(i);
		}
	}
	stack[l++]=i;//�ѵ�ǰ�����뻺���� 
	for(int k=0;k<l;k++)
	{
		printf("%d,",stack[k]+1); 
	}
	printf("\n");
}
int main()
{
	f(1,0);
}
