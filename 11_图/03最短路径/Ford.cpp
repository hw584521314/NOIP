#include<stdio.h>
#include<string.h>
int dis[100];
int V[100];//顶点信息 
int F[100];//顶点链表 
struct line{
	int to;
	int value;
	int from;
	int next;
};
line lines[100];
int N;//多少个顶点
int M;//多少条边 




int main()
{
	//读入图数据 
	scanf("%d%d",&N,&M);
	int from,to,v;
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d%d",&from,&to,&v);
		lines[i].to=to;
		lines[i].value=v;
		lines[i].from=from;
		lines[i].next=F[from];
		F[from]=i;
	}
	scanf("%d%d",&from,&to);
	//把from初始化
	memset(dis,0x7f,sizeof(dis));
	dis[from]=0; 
	int from1,to1,value1;
	for(int i=1;i<=N-1;i++)
	{
		for(int j=1;j<=M;j++)
		{
			from1=lines[j].from;to1=lines[j].to;value1=lines[j].value;
			if(dis[from1]+value1<dis[to1])
			{
				dis[to1]=dis[from1]+value1;
			}
		}	
	} 
	printf("%d",dis[to]);
}
