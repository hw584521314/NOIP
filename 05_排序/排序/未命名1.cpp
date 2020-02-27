//高精度加法 
#include<stdio.h>
#include<string.h>
int a[200]={0};
int b[200]={0};
int c[201]={0};
char d[201];

int main()
{
	scanf("%s",d);
	int l=strlen(d);
	int index=0;
	for(int i=l-1;i>=0;i--)
	{
		a[index++]=d[i]-'0';
	}
	scanf("%s",d);
	l=strlen(d);
	index=0;
	for(int i=l-1;i>=0;i--)
	{
		b[index++]=d[i]-'0';
	}
	
	//
	int p=0;
	int sum;
	for(int i=0;i<200;i++)
	{
		sum=a[i]+b[i]+p;
		c[i]=sum%10;
		p=sum/10;
	}
	
	index=200;
	while(c[index]==0)
	{index--;}
	for(int i=index;i>=0;i--)
	{
		printf("%d",c[i]);
	}
}



