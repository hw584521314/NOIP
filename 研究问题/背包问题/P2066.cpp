#include<stdio.h>
#include<iostream>
using namespace std;
int M,N;
int in[16][16];
int df[16][16][2];

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&in[i][j]);
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int m=0;m<=M;m++)
		{
			for(int k=0;k<=m;k++)
			{
				int t=df[i-1][k][0]+in[i][m-k];
				if(t>df[i][m][0])
				{

					df[i][m][0]=t;
					//���浱ǰ�⹫˾����һ����m̨��������£�������ţ�����Ҫ����̨���� 
					//������˵����Ҳ������ǰһ����˾�����k̨���������������·�� 
					df[i][m][1]=m-k;
				}
				
			}
		}
	}
	printf("%d\n",df[N][M][0]);
	int m=M;
	int detail[16];
	//·��������� 
	for(int i=N;i>=1;i--)
	{
		detail[i]=df[i][m][1];
		m=m-df[i][m][1];
	}
	for(int i=1;i<=N;i++)
	{
		printf("%d %d\n",i,detail[i]);
	}
	
}

