#include<stdio.h>
int A[10001]={60000};
int B[10001];
int idx=0;
int idx2=0;
int main()
{
	
	int a;
	for(;scanf("%d",&a)!=EOF;)
	{
	
		if(a<=A[idx])
		{
			A[++idx]=a;
		}
		else
		{
			for(int i=1;i<=idx;i++)
			{
				if(a>A[i])
				{
					A[i]=a;
					break;
				}
			}
		}
		if(a>B[idx2])
		{
			B[++idx2]=a;
		}
		else{
			for(int i=1;i<=idx2;i++)
			{
				if(a<B[i])
				{
					B[i]=a;
					break;
				}
			}
		}
	}
	printf("%d\n%d",idx,idx2);
}
