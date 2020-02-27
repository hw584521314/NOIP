#include<stdio.h>
int a[12]={6,2,4,3,6,9,8,7,1,5};
void sort(int l,int r)
{
	if(l>=r) return;
	int l1=l,r1=r;
	int t;
	while(l1<r1)
	{
		while(a[r1]>a[l]&&l1<r1) r1--;
		while(a[l1]<=a[l]&&l1<r1) l1++;
		if(l1>=r1) 
			break;
		t=a[r1];a[r1]=a[l1];a[l1]=t;
	}
	t=a[l];a[l]=a[l1];a[l1]=t;
	sort(l,l1-1);
	sort(l1+1,r);
}
int main()
{
	sort(0,9);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
}
