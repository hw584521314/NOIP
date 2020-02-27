#include<stdio.h>
/*
5 7
1 2 2
1 3 3
1 4 7
2 5 2
2 3 1
3 4 1
3 5 6
*/
int input[100][100];
int G,N;
int book[100];//白点
int Min[100];//和所有白点中的最短开销 
int INF=99999;
int findBlue()
{
	int tMin=INF,idx=0;
	for(int i=1;i<=N;i++)
	{
		if(book[i]==0)
		{
			if(Min[i]<tMin)
			{
				tMin=Min[i];
				idx=i;
			}
		}
	}
	return idx;
}
int main()
{
	scanf("%d%d",&G,&N);
	int from,to,v; 
	for(int i=0;i<N;i++)
	{
		scanf("%d%d%d",&from,&to,&v);
		input[from][to]=v;
		input[to][from]=v;
	}
	//假设从1号点出发
	for(int i=1;i<=N;i++)
	{
		Min[i]=INF;
	}
	Min[1]=0; 
	int minPath=0;
	for(int i=0;i<N-1;i++)
	{
		//找到最优的蓝点 
		int t=findBlue();
		minPath+=Min[t];
		
		book[t]=1;//放入白点集合 
		//把该蓝点的最近蓝点更新
		for(int j=1;j<=N;j++)
		{
			if(input[t][j]!=0&&book[j]==0)
			{
				if(input[t][j]<Min[j])
				{
					Min[j]=input[t][j];
				}
			}
		 } 
	}
	printf("%d",minPath);
} 
