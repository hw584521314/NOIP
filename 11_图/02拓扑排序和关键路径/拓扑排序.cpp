//拓扑排序主要解决有向无环图的依赖关系解决
//完成拓扑排序后，后面节点一定是有向图的后继节点，而不会是前驱节点
//例如可以完成工作安排等等。 
//首先计算每个节点的入度

#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;

main()
{
	queue<int> q;//队列，用于广度优先搜索。每次把入度为0的压入 
	int in[100]={0};//保存每个节点的入度是多少 
	vector<int> edge[100];//保存每个节点的边的关系 
	int n;//n个节点 
	int m;//m行输入 
	scanf("%d%d",&n,&m);
	//读取有向图 
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
	} 
	//计算每个节点的入度 按照题目要求，没有0，从1开始 
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<edge[i].size();j++)
		{
			in[edge[i][j]]++;
		}
	} 
	//将入度为0的压入 
	for(int i=1;i<=n;i++)  //n  节点的总数
	{
		if(in[i]==0) q.push(i);  //将入度为0的点入队列
	}
	 
	vector<int>ans;   //ans 为拓扑序列
	while(!q.empty())
	{
		int p=q.front(); q.pop(); // 选一个入度为0的点，出队列
		ans.push_back(p);//把结果压入vector 
		for(int i=0;i<edge[p].size();i++) 
		{//这个点即将删除，删除前首先将每个子节点的入度减少 
			int y=edge[p][i];
			in[y]--;
			if(in[y]==0)//如果为0，则压入队列 
				q.push(y);  
		}
	}
	if(ans.size()==n)   
	{
		for(int i=0;i<ans.size();i++)
			printf( "%d ",ans[i] );
		printf("\n");
	}
	else printf("No Answer!\n");   //  ans 中的长度与n不相等，就说明无拓扑序列
	
}




