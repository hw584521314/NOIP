//方法1：暴力枚举 
#include<stdio.h>
int n=5;
int a[10][10]={
{7},
{3,8},
{8,1,0},
{2,7,4,4},
{4,5,2,6,5}};
int ax[10];
int ay[10];
int rx[10],ry[10];
int rlevel;
int max=0;
void f(int x,int y,int level,int total){
	if(x<0||x>=n)
	{
		return;
	}
	if(y<0||y>=n)
	{
		return;
	}
	ax[level]=x;
	ay[level]=y;
	total=total+a[x][y];
	if(x==n-1)
	{
		if(total>max)
		{
			max=total;
			rlevel=level+1;
			for(int i=0;i<rlevel;i++)
			{
				rx[i]=ax[i];ry[i]=ay[i];
			}
		}
		return;
	}
	f(x+1,y,level+1,total);
	f(x+1,y+1,level+1,total);
}
int main()
{
	
	/*scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}*/
	f(0,0,0,0);
	printf("%d\n",max);
	for(int i=0;i<rlevel;i++)
	{
		printf("(%d,%d)->",rx[i],ry[i]);
	}
}
