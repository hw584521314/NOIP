//—°‘Ò≈≈–Ú
#include<stdio.h>
int a[5]={4,5,3,1,2};
int main()
{
	int temp;
	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];a[i]=a[j];a[j]=temp;	
			}
		}
	}
	for(int i=0;i<5;i++)
	{
		printf("%d,",a[i]);
	}
	
}
