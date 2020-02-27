#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int a[2][1001];
int main()
{
 	int R;
	cin>>R;
	int b;
	int mm=0;
	for(int i=1;i<=R;i++)
	{
		int cur=1&i;
		int pre=1&(i-1);
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&b);
			a[cur][j]=max(a[pre][j],a[pre][j-1])+b;
			if(a[cur][j]>mm) mm=a[cur][j];
		}
	}  
	printf("%d",mm);
 } 
