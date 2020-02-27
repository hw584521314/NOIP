#include<stdio.h>
#include<string.h>
int a[100]={0};
int b[100]={0};
int c[10000]={0};
char buffer[100];
int main()
{
	//读入数据a 
	scanf("%s",buffer);
	int l1=strlen(buffer);
	int index=0;
	for(int i=l1-1;i>=0;i--)
	{
		a[index++]=buffer[i]-'0';
	}
	//读入b 
	scanf("%s",buffer);
	int l2=strlen(buffer);
	index=0;
	for(int i=l2-1;i>=0;i--)
	{
		b[index++]=buffer[i]-'0';
	}
	//计算
	int temp,i,j;
	for(i=0;i<l2;i++)
	{
		//i代表b的每一个数，j代表a的每一个数 
		int p=0;//进位
		for(j=0;j<l1;j++)
		{
			temp=b[i]*a[j]+c[i+j]+p;
			c[i+j]=temp%10;
			p=temp/10;
		}	
		//乘法进位分配完毕
		int tempi=i+j;
		while(p!=0)
		{
			c[tempi++]=p%10;
			p=p/10;
		}		 
	} 
	index=10000-1;
	while(c[index]==0){
		index--;
	}
	for(int i=index;i>=0;i--)
	{
		printf("%d",c[i]);
	}
	return 0;	
} 
