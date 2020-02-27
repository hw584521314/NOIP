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
	int pre;//����ָ�� 
	int to;//��һ������ 
	int val;//Ȩֵ 
}; 
struct P{
	int dis;//���� ���� 
	int g;//��ʾ�ĸ�����  
	bool operator<(const P &b) const
	{
		return dis>b.dis;
	}
};
Line total[100];
int idx=1;
int lines[100];//��¼ÿ����������� 
int dis[100];
int pre[100];//ǰ���ڵ� 
int book[100];//�׵㼯�� 
int INF=999999;
int G;//G��ʾ�������
int E;//��ʾ�ߵĸ��� 
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
		//����ͼ��double 
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
	//G�����������ˣ��ͽ����� 
	while(c<=G)
	{
		//�Ӷ�����ȡ����ǰ����� 
		p=que.top();que.pop();	
		if(book[p.g]) continue;
		book[p.g]=1;//��ɰ׵� 
		printf("%d->%d %d\n",pre[p.g],p.g,p.dis);//��ӡ���� 
		minPath+=dis[p.g];//��С�����������������ǵ���Сֵ
		//�����ö�����������бߣ���ͼ�������㡣��������ܶ�������и��ŵĸ��¡���
		//����dis��ͬʱ�Ѹ��õ�����ѹ����С� 
		for(int i=lines[p.g];i;i=total[i].pre)
		{
			int to=total[i].to;//��һ���� 
			if(!book[to])
			{//��������� 
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
