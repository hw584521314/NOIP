#include<stdio.h>
int a[]={5,3,4,8,6,1,7,2,10,9,6};
void qsort(int left,int right)
{
	int f=a[left];
	int tl=left;
	int tr=right;
	int t;
	if(left>=right) return;
	while(tl<tr)
	{
		while(a[tr]>=f&&tl<tr) tr--;
		while(a[tl]<=f&&tl<tr) tl++;	
		if(tl>=tr) break;
		t=a[tl];a[tl]=a[tr];a[tr]=t;
	}
	t=a[left];a[left]=a[tr];a[tr]=t;
	qsort(left,tr-1);
	qsort(tr+1,right);
}

int main()
{
	qsort(0,10);
	for(int i=0;i<11;i++)
	{
		printf("%d,",a[i]);
	}
	
 } 
