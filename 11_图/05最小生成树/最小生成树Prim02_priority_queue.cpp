#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
/*
5 7
1 2 2
1 4 3
1 4 7
2 5 2
2 3 1
3 4 1
3 5 6
*/
struct Line{
	int pre;//链表指针 
	int to;//下一个顶点 
	int val;//权值 
}; 
struct P{
	int dis;//保存 距离 
	int g;//表示哪个顶点  
	bool operator<(const P &b) const
	{
		return dis>b.dis;
	}
};
Line total[100];
int idx=1;
int lines[100];//记录每个顶点的链表 
int dis[100];
int pre[100];//前驱节点 
int book[100];//白点集合 
int INF=999999;
int G;//G表示顶点个数
int E;//表示边的个数 
priority_queue<P> que;
int main()
{
	cin>>G>>E;
	int minPath=0; 
	int from,to,value;
	for(int i=1;i<=E;i++)
	{
		cin>>from>>to>>value;
		total[idx].to=to;
		total[idx].val=value;
		total[idx].pre=lines[from];
		lines[from]=idx;
		idx++;
		//无向图，double 
		total[idx].to=from;
		total[idx].val=value;
		total[idx].pre=lines[to];
		lines[to]=idx;
		idx++;
	}
	for(int i=1;i<=G;i++)
	{
		dis[i]=INF;
	}
	dis[1]=0;
	P p={0,1};
	que.push(p);
	int c=1;
	//G个顶点找完了，就结束了 
	while(c<=G)
	{
		//从队列中取出当前最近的 
		p=que.top();que.pop();	
		if(book[p.g]) continue;
		book[p.g]=1;//变成白点 
		printf("%d->%d %d\n",pre[p.g],p.g,p.dis);//打印顶点 
		minPath+=dis[p.g];//最小生成树代价增加我们的最小值
		//遍历该顶点出发的所有边，试图更新蓝点。如果发现能对蓝点进行更优的更新。则
		//更新dis，同时把更好的蓝点压入队列。 
		for(int i=lines[p.g];i;i=total[i].pre)
		{
			int to=total[i].to;//下一个点 
			if(!book[to])
			{//如果是蓝点 
				if(dis[to]>total[i].val)
				{	
					pre[to]=p.g;				
					dis[to]=total[i].val;
					P t={dis[to],to};
					que.push(t);
				}
			}
		}
		c++;

	}
	printf("\n%d",minPath);
} 
