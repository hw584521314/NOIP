#include<stdio.h>
#include<string.h>
char a[200]={0};
char b[200]={0};
char d[200]={0};
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
	//首先判断谁大谁小
	char *bjs;
	char *js;
	int flag=0;
	for(int i=200-1;i>=0;i--)
	{
		if(a[i]>b[i])
		{
			bjs=a;js=b;break;
		}
		else if(a[i]<b[i])
		{
			bjs=b;js=a;flag=1;break;
		}
	} 
	//开始做减法
	int jw=0;//借位标志
	int beijianshu;
	int temp;
	for(int i=0;i<200;i++)
	{
		beijianshu=bjs[i]-jw;//首先减掉之前的借位
		temp=beijianshu-js[i]; 
		if(temp>=0)
		{//够减，不借位 
			d[i]=temp;jw=0;
		} 
		 else
		{//不够减，借个位 
		 	d[i]=temp+10;jw=1;
		} 
	}
	//获取什么时候该开始输出 
	idx=200-1;
	for(;idx>=0;idx--)
	{
		if(d[idx]!=0)
		{
			break;
		}
	}
	//idx就是要求的值，开始全部输出 
	if(flag==1)
	{
		printf("-");
	}
	for(int i=idx;i>=0;i--)
	{
		printf("%d",d[i]);
	}
}
