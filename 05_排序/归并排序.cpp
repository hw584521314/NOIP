#include<stdio.h>
int temp[100];
int a[10]={6,  1 , 2, 7 , 9 , 3 , 4 , 5 ,10,  8};
int mergeSort(int l,int r)
{
	if(l>=r) return 0;
	//归 
	int mid=(l+r)/2;
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	//并 
	int idx=0;
	int l1=l,r1=mid,l2=mid+1,r2=r;
	//注意l2和 注意下面的<= 
	while(l1<=r1&&l2<=r2)
	{
		if(a[l1]<a[l2])
		{
			temp[idx++]=a[l1++];
		}
		else
		{
			temp[idx++]=a[l2++];
		}
	}
	while(l1<=r1)
	{
		temp[idx++]=a[l1++];
	}
	while(l2<=r2)
	{
		temp[idx++]=a[l2++];
	}
	//排好序的内容，放置回去 
	for(int i=0,j=l;i<idx;i++,j++)
	{
		a[j]=temp[i];
	}
}
int main()
{
	mergeSort(0,9);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
}
