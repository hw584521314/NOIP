
//选择三个数，他们的和能否构成一个数b 
//不可重复取 
#include<stdio.h>
int a[6]={5,4,2,9,11,8};


int main()
{
	int b=19;
	for(int i=0;i<6;i++)
	{
		for(int j=i+1;j<6;j++)
		{
			for(int k=j+1;k<6;k++)
			{
				if(a[i]+a[j]+a[k]==b)
				{
					printf("YES");
					return 0;
				}
			}
		}
	}
	printf("NO");
 } 

