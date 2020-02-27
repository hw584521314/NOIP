#include<stdio.h>
#include<vector>
using namespace std;
//������Ȩ�ߣ�����ͼ�������·��
//�����һ��Ϊ������+����
//ʹ��ford�㷨 
/*
7 10
1 2 2
1 3 5
2 3 4
2 4 6
2 5 10 
3 4 2
4 6 1
5 6 3
5 7 5
6 7 9
*/
struct Edge{
	int from,to,v;
};
int G;//�涥����� 
vector<Edge> edges;//�����еı� 
const int INF=0x7fffffff;
int dis[8];
int pre[8];
int main()
{
	int a,b,c;
	scanf("%d%d",&G,&a);
	Edge t; 
	for(int i=0;i<a;i++)
	{
		scanf("%d%d%d",&t.from,&t.to,&t.v);
		edges.push_back(t); 
	}
	//��ʼ��dis����
	for(int i=0;i<=G;i++)
	{
		dis[i]=INF;
	}
	dis[1]=0; 
	while(1)
	{
		bool isUpdate=false;
		for(int i=0;i<edges.size();i++)
		{
			Edge e=edges[i];
			if(dis[e.from]!=INF&&(dis[e.to]>dis[e.from]+e.v))
			{
				dis[e.to]=dis[e.from]+e.v;
				pre[e.to]=e.from;			
				isUpdate=true;
			}
		}
		if(isUpdate==false) break;
	}
	for(int i=1;i<=G;i++)
	{
		printf("%d,",dis[i]);
	}
	printf("\n");
	//��ӡÿһ���յ�����·����ϸ
	int detail[8];
	int count=0;
	for(int i=1;i<=G;i++)
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
