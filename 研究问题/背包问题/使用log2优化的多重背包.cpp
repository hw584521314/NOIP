#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
int v[101];
int w[101];
int m[101];
int dp[40001];
int main()
{
	int N,W;
	scanf("%d%d",&N,&W);
	for(int i=1;i<=N;i++)
	{
		scanf("%d%d%d",&v[i],&w[i],&m[i]);
	}
	for(int i=1;i<=N;i++)
	{
		
		//printf("di %d ge\n",i);
		int num=m[i];
		for(int j=1;num>0;j*=2)
		{
			if(j>num) j=num;
			num-=j;
			//printf("zhi you %d ge\n",j);
			for(int k=W;k-w[i]*j>=0;k--)
			{
				dp[k]=max(dp[k],dp[k-w[i]*j]+v[i]*j);
			}
			
			/*for(int kk=0;kk<=W;kk++)
			{
				printf("%d ",dp[kk]);
			}
			printf("\n");*/
		}
		
		
	}
	printf("%d",dp[W]);
	
}
