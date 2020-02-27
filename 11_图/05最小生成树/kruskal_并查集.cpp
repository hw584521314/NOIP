#include<stdio.h> 
#include<algorithm>
using namespace std;
//ʹ�ò��鼯��ʵ���ж����������Ƿ����ڲ�ͬ�ļ���
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

int group[100];
int find(int x)
{
	if(group[x]==x) return x;
	return group[x]=find(group[x]);
} 
void join(int x,int y)
{
	int px=find(x);
	int py=find(y);
	if(px==py)
	{
		return;
	}
	else
	{
		group[px]=py;
	}
}
int from[100];
int to[100];
int line[100];
int idx[100];
bool cmp1(int x,int y)
{
	if(line[x]<line[y]) return true;
	return false;
}
int main()
{
	int N,V;
	int count=0;
	int minPath=0;
	scanf("%d%d",&N,&V);
	for(int i=0;i<V;i++)
	{
		scanf("%d%d%d",&from[i],&to[i],&line[i]);
		idx[i]=i;
	}
	//�Ա߽����±����� 
	sort(idx,idx+V,cmp1);

	//���鼯��ʼ��
	for(int i=1;i<=N;i++)
	{
		group[i]=i;
	} 
	int t1,t2;
	for(int i=0;count<N-1;i++)
	{
		t1=from[idx[i]];
		t2=to[idx[i]];
		if(find(t1)!=find(t2))
		{//�ñߵ��������㲻��һ�������У������Ž����� 
			join(t1,t2);
			minPath+=line[idx[i]];
			count++;
		}
	}
	printf("%d",minPath);
	return 0;
 } 
