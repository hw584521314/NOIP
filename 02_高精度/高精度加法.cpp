#include<stdio.h>
#include<string.h> 
char a[200]={0};
char b[200]={0};
int main()
{
	char c[200];
	//读入数并倒序放置 
	scanf("%s",c);
	int l=strlen(c);
	int idx=0;
	for(int i=l-1;i>=0;i--)
	{
		a[idx]=c[i]-'0';
		idx++;
	}
	scanf("%s",c);
	l=strlen(c);
	idx=0;
	for(int i=l-1;i>=0;i--)
	{
		b[idx]=c[i]-'0';
		idx++;
	}
	//开始做加法运算
	int jw=0;//进位 
	int temp;
	for(int i=0;i<200;i++)
	{
		temp=a[i]+b[i]+jw;
		a[i]=temp%10;
		jw=temp/10;	
	} 
	//获取什么时候该开始输出 
	idx=200-1;
	for(;idx>=0;idx--)
	{
		if(a[idx]!=0)
		{
			break;
		}
	}
	//idx就是要求的值，开始全部输出 
	for(int i=idx;i>=0;i--)
	{
		printf("%d",a[i]);
	}
}
