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
	//开始进行乘法运算
	int jw=0;
	int temp;
	for(int i=0;i<200;i++)
	{//i代表乘数的索引 
		jw=0;//进位归零 
		for(int j=0;j<200;j++)
		{//j代表被乘数的索引 
			temp=b[i]*a[j]+jw;//用乘数b[i]依次去乘以被乘数a[j] 
			temp=temp+d[i+j];//加上原来的结果里的值，由于是b[i]，所以起点变成d[i] 
			d[i+j]=temp%10;
			jw=temp/10; 
		}
	}
	//开始进行输出
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
	
	for(int i=idx;i>=0;i--)
	{
		printf("%d",d[i]);
	}
}
