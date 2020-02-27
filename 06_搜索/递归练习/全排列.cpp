//х╚ееап 
#include<stdio.h>
int count;
char t[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int a[26]={0};
char b[26];
int index=0;
int f(int n)
{
	if(n<0)
	{
		for(int i=0;i<count;i++)
		{
			printf("%c",b[i]);
		}
		index++;
		printf("\n");
		return 0;
	}
	for(int i=0;i<count;i++)
	{
		if(a[i]==0)
		{
			a[i]=1;
			b[n]=t[i];
			f(n-1);
			a[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&count);
	f(count-1);
	printf("%d",index);
}
