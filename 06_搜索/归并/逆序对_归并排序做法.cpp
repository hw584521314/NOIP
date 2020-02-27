#include<stdio.h>
#include<memory.h>
int tmp[10000];
int a[10000]={8,2,5,1,6,7,3,4,10,9};
int c=0;
void mergeSort(int l,int r)
{
	if(l>=r) return;
	int m;
	m=(l+r)/2;
	mergeSort(l,m);
	mergeSort(m+1,r);
	int t1=l,t2=m+1,t3=0;
	while(t1<=m&&t2<=r)
	{
		if(a[t1]<=a[t2]) 
		{
			tmp[t3]=a[t1];
			t1++;
		}
		else
		{
			tmp[t3]=a[t2];
			t2++;
			c+=m-t1+1;
		}
		t3++;
	}
	while(t1<=m) tmp[t3++]=a[t1++];
	while(t2<=r) tmp[t3++]=a[t2++];
	memcpy(a+l,tmp,t3*sizeof(int));
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	} 
	mergeSort(0,N-1);
	printf("%d",c);
}
