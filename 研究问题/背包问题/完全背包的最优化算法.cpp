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
		for(int j=t[i];j<=T;j++)
		{
			f[j]=max(f[j],f[j-t[i]]+v[i]);
		}
	} 
	printf("%d",f[T]); 
}
