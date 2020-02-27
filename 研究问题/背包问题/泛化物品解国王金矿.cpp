#include<stdio.h>
int a[]={200,300,350,400,500};
int b[]={3,4,3,5,5};
int dp[11];
int goods(int x,int y)
{
	if(x==0)
	{
		if(y<3) return 0;
		else return 200;
	}
	else if(x==1)
	{
		if(y<4) return 0;
		else return 300;
	}
	else if(x==2)
	{
		if(y<3) return 0;
		else return 350;
	}
	else if(x==3)
	{
		if(y<5) return 0;
		else return 400;
	}
	else if(x==4)
	{
		if(y<5) return 0;
		return 500;
	}
}

int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=10;j>=0;j--)
		{
			for(int k=0;k<=j;k++)
			{
				if(dp[j]<dp[k]+goods(i,j-k))
				{
					dp[j]=dp[k]+goods(i,j-k);
				}
			}
			
		}
		for(int j=0;j<=10;j++)
		{
			printf("%d,",dp[j]);
		}
		printf("\n");
	}
	printf("%d",dp[10]);
}
