#include<stdio.h>
int a[4]={1,2,4,7};
int S=13;
int N=4;
int r[4];
//int idx;
void f(int s,int n,int idx)
{
	
	if(s==S) 
	{
		for(int i=0;i<idx;i++)
		{
			printf("%d,",r[i]);
		}
		printf("\n");
		return ;
	}
	if(n>=4)
	{
		return ;
	}
	r[idx]=a[n];
	f(s+a[n],n+1,idx+1);	
	f(s,n+1,idx);
	return ;
}

int main()
{
	f(0,0,0);
	//printf("%d",b);
	return 0;
} 
