#include<stdio.h>
int a[5][5]={
{7},
{3, 8},
{8, 1, 0}, 
{2, 7, 4, 4},
{4, 5, 2, 6, 5}};
int b[5][5]={0};
int f(int i,int j)
{
	if(i==4)
	{//���һ�У�ֱ�ӷ��ض�Ӧֵ 
		return a[i][j];
	}
	if(b[i][j]!=0) return b[i][j];
	int t1,t2;
	//����һ�У���˭�󣬾�ȡ˭��Ȼ����ϵ�ǰ���ֵ 
	t1=f(i+1,j); 
	t2=f(i+1,j+1);
	b[i][j]=a[i][j]+(t1>t2?t1:t2);
	return b[i][j];	
}

int main()
{
	int t;
	t=f(0,0);
	printf("%d",t);
} 
