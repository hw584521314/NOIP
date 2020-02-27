#include<stdio.h>
#include<string.h>
int dis[100];
int V[100];//顶点信息 
int F[100];//顶点链表 
struct line{
	int to;
	int value;
	int next;
};
line lines[100];
int N;//多少个顶点
int M;//多少条边 
void djskla(int start)
{
	memset(dis,0x7f,sizeof(dis));
	dis[start]=0; 
	
	for(int k=1;k<=N;k++)
	{
		//1.从剩下的F当中找出dis最小的
		int min=10000,minIdx=0;
		for(int i=1;i<=N;i++)
		{
			if(V[i]==0&&dis[i]<min)
			{
				min=dis[i];minIdx=i;
			}
		} 
		//2.把这个点加入V
		V[minIdx]=1;
		//3.遍历这个点能到达的其他点，根据该点的路径和边消费，更新其他点的值
		for(int j=F[minIdx];j!=0;j=lines[j].next)
		{
			if(dis[lines[j].to]>dis[minIdx]+lines[j].value)
			{
				dis[lines[j].to]=dis[minIdx]+lines[j].value;
			}
		} 
	}	
}

 

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
		lines[i].next=F[from];
		F[from]=i;
	}
	scanf("%d%d",&from,&to);
	djskla(from);
	
}
