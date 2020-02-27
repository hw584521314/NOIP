#include<stdio.h>
#include<iostream>
using namespace std;
int M,N;
int in[16][16];
int df[16][16];

//前n个公司，分m台机器的最优解 
int  f(int n,int m)
{
	if(df[n][m]!=0) return df[n][m]; 
	if(n==0)
	{
		return 0;
	} 
	int t=0;
	for(int i=0;i<=m;i++)
	{
		df[n][m]=max(df[n][m],f(n-1,i)+in[n][m-i]);	
	}
	return df[n][m]; 
} 

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&in[i][j]);
		}
	}
	int a=f(N,M);
	printf("%d\n",a);

}

