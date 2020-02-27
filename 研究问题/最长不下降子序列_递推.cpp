#include<stdio.h>
int min(int x,int y)
{
	return x>y?y:x;
}
int main()
{
	int a[8]={1,3,1,5,9,7,4,8};
	int b[8];
	for(int i=0;i<8;i++)
	{
		b[i]=1000;
	}
	int count=1;
	b[0]=a[0];
	int t;
	for(int i=1;i<8;i++)
	{
		if(a[i]>=b[count-1])
		{
			b[count]=a[i];
			count++;
		}
		else
		{
			//只有a[i]大于之前项的前提下，才有更新的必要 
			if(count==1||a[i]>b[count-2])
			{
				b[count-1]=a[i];
			}
		}
	}
	printf("%d",count);
}
