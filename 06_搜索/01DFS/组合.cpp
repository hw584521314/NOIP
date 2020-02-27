#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,k; 
int a[40]={1,2,3,4,5,6,7,8,9,10};
int b[40];
int c;
void go(int t)
{
	if(t>=k)
	{
		for(int i=0;i<k;i++)
		{
			printf("%d ",b[i]);
		}
		printf("\n");
		
		return ;
	}
	for(int i=t;i<n;i++)
	{
		b[t]=a[i];
		go(i+1);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	
	go(0);
	
} 
