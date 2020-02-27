//øÏÀŸ≈≈–Ú
#include<stdio.h>
//int a[10]={4,5,2,1,9,8,7,6,3,4};
//int a[10]={1,2,3,4,5,6,7,8,9,10};
int a[10]={10,9,8,7,6,5,4,3,2,1};
void f(int left,int right)
{
	int temp;
	if(left>=right)
	{
		return;
	}
	if(left+1==right)
	{
		if(a[left]>a[right])
		{
			temp=a[left];a[left]=a[right];a[right]=temp;
		}
		return;
	}
	int mid=a[left];
	int tempLeft=left;
	int tempRight=right;
	
	while(1)
	{
		while(a[tempRight]>mid&&tempLeft<=tempRight){
			tempRight--;
		}
		while(a[tempLeft]<=mid&&tempLeft<=tempRight)
		{
			tempLeft++;
		}
		if(tempLeft>=tempRight) 
			break; 
		else
			temp=a[tempLeft];a[tempLeft]=a[tempRight];a[tempRight]=temp;
	
	}
	temp=a[tempLeft-1];a[tempLeft-1]=a[left];a[left]=temp; 
	f(left,tempLeft-1);
	f(tempLeft,right);	
}

int main()
{
	f(0,9);
	for(int i=0;i<10;i++)
	{
		printf("%d,",a[i]);
	}
}
 
