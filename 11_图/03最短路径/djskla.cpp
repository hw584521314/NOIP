#include<stdio.h>
#include<string.h>
int dis[100];
int V[100];//������Ϣ 
int F[100];//�������� 
struct line{
	int to;
	int value;
	int next;
};
line lines[100];
int N;//���ٸ�����
int M;//�������� 
void djskla(int start)
{
	memset(dis,0x7f,sizeof(dis));
	dis[start]=0; 
	
	for(int k=1;k<=N;k++)
	{
		//1.��ʣ�µ�F�����ҳ�dis��С��
		int min=10000,minIdx=0;
		for(int i=1;i<=N;i++)
		{
			if(V[i]==0&&dis[i]<min)
			{
				min=dis[i];minIdx=i;
			}
		} 
		//2.����������V
		V[minIdx]=1;
		//3.����������ܵ���������㣬���ݸõ��·���ͱ����ѣ������������ֵ
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
	//����ͼ���� 
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
