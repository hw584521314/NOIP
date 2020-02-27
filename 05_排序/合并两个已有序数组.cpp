#include<stdio.h>
int main()
{
	int a[5]={4,5,7,8};
	int b[5]={1,2,3,6,9};
	int c[20];
	int la=4,lb=5;
	int l1=0,l2=0;
	int idx=0;
	while(l1<la&&l2<lb)
	{
		if(a[l1]<b[l2])
		{
			c[idx++]=a[l1++];
		}
		else
		{
			c[idx++]=b[l2++];
		}
	}
	while(l1<la)
	{
		c[idx++]=a[l1++];
	}
	while(l2<lb)
	{
		c[idx++]=b[l2++];
	}
	for(int i=0;i<idx;i++)
	{
		printf("%d ",c[i]);
	}
 } 
