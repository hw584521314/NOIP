#include<stdio.h>
#include<iostream>
using namespace std;
int M,N;
int in[16][16];
int df[16][16][2];

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
	for(int i=1;i<=N;i++)
	{
		for(int m=0;m<=M;m++)
		{
			for(int k=0;k<=m;k++)
			{
				int t=df[i-1][k][0]+in[i][m-k];
				if(t>df[i][m][0])
				{

					df[i][m][0]=t;
					//保存当前这公司，在一共有m台机器情况下，获得最优，它需要多少台机器 
					//侧面来说，它也保存了前一个公司分配的k台机器，保存了这个路径 
					df[i][m][1]=m-k;
				}
				
			}
		}
	}
	printf("%d\n",df[N][M][0]);
	int m=M;
	int detail[16];
	//路径逆序输出 
	for(int i=N;i>=1;i--)
	{
		detail[i]=df[i][m][1];
		m=m-df[i][m][1];
	}
	for(int i=1;i<=N;i++)
	{
		printf("%d %d\n",i,detail[i]);
	}
	
}

