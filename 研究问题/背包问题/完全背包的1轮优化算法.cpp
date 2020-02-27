#include<stdio.h>
#include<iostream>
using namespace std;
int T,M;
int t[100];
int v[100];
int f[100];

int main()
{
		scanf("%d%d",&T,&M);
	
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",&t[i],&v[i]);
	}
	//初始化
	for(int i=0;i<=T;i++)
	{
		f[i]=0;
	}
	//开始迭代
	for(int i=0;i<M;i++)
	{
		for(int j=T;j>=0;j--)
		{
			int k=0;
			
			while(j-t[i]*k>0)
			{
				f[j]=max(f[j],f[j-t[i]*k]+v[i]*k);			
				k=k*2;
			}
			
		}
	} 
	printf("%d",f[T]); 
}
