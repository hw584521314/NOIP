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
	
