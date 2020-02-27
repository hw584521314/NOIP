#include<stdio.h>
int n=5;
int a[10][10]={
{7},
{3,8},
{8,1,0},
{2,7,4,4},
{4,5,2,6,5}};
//f(x,y) = max(f(x-1,y),f(x-1,y-1))
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	for(int i=1;i<n;i++)
	{
		int x,y=0;
		for(int j=0;j<n;j++)
		{
			
			x=a[i-1][j]+a[i][j];
			if(j-1>=0)
			{
				y=a[i-1][j-1]+a[i][j];
			}
			a[i][j]=max(max(x,y),a[i][j]);
		}
	}
	int m=0;
	for(int i=0;i<n;i++)
	{
		if(a[n-1][i]>m)
		{
			m=a[n-1][i];
		}
	}
	printf("%d",m);
}
