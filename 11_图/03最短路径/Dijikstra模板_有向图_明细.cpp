#include<queue>
#include<stdio.h>
using namespace std;
struct Node{
	int v;//路径 
	int p;//顶点 
	bool operator<(const Node &b) const
	{
		return v<b.v;
	}
};
priority_queue<Node> q;
struct Edge{
	int to,cost;
}; 
vector<Edge> G[10];
int dis[10];
int pre[10];
int N,M;
const int INF=0x7fffffff;
int main()
{
	scanf("%d%d",&N,&M);
	int from,to,cost;
	for(int i=0;i<M;i++)
	{
		scanf("%d%d%d",&from,&to,&cost);
		Edge t={to,cost};
		G[from].push_back(t);
	} 
	for(int i=0;i<=N;i++)
	{
		dis[i]=INF;
	}
	dis[1]=0;
	int n=1;
	Node t={0,1};
	q.push(t);
	while(n<N)
	{
		t=q.top();q.pop();
		int from=t.p;
		for(int i=0;i<G[from].size();i++)
		{
			int a=dis[from]+G[from][i].cost;
			int to=G[from][i].to;
			if(dis[to]>a)
			{				
				dis[to]=a;
				Node tt={a,to};
				q.push(tt);
				pre[to]=from;
			}			
		}
		n++;
	}
	for(int i=1;i<=N;i++)
	{
		printf("%d ",dis[i]);
	}
	printf("\n");
	//打印每一个终点的最短路径明细
	int detail[8];
	int count=0;
	for(int i=1;i<=N;i++)
	{
		if(i!=1)
		{
			count=0;
			detail[count]=i;count++;
			for(int j=pre[i];j!=0;j=pre[j])
			{
				detail[count]=j;count++;
			}
			for(int j=count-1;j>=0;j--)
			{
				printf("%d->",detail[j]);
			}
			printf("\n");
		}
	 } 
}
