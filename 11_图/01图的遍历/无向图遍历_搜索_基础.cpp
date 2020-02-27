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
	//如果为1，则该为2，如果为2，该为1 
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

	//对当前行，遍历每列，看是否有某一列有值，如果有值，说明该列对应的点可以访问 
	for(int j=0;j<5;j++)
	{
		if(j==i) continue;
		if(a[i][j]==1)
		{
			//把当前点对应的路封了 ，避免其他点走到这里回环 
			SetColumn(i);
			stack[l]=i;
			f(j,l+1);
			//解封路 
			SetColumn(i);
		}
	}
	stack[l++]=i;//把当前数放入缓冲中 
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
