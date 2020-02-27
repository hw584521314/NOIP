#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int a[1001][1001];
int c[1001][1001];
int main()
{
 	int R;
	cin>>R;
	int b;
	int mm=0;
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]);			
		}
	}  
	for(int i=R-1;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			int t;
			if(a[i+1][j]>a[i+1][j+1])
			{//—°‘Ò¡À◊Û±ﬂ 
				c[i][j]=0;
				t=a[i+1][j];
			}
			else
			{//—°‘Ò¡À”“±ﬂ 
				c[i][j]=1;
				t=a[i+1][j+1];
			}
			a[i][j]+=t;
		} 
	}
	printf("%d\n",a[1][1]);
	int j=1;
	for(int i=1;i<R;i++)
	{
		if(c[i][j]==0)
		{
			printf("◊Û±ﬂ,");
		}
		else
		{
			printf("”“±ﬂ,");
			j++;
		}
	}
 } 
