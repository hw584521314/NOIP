//Õ∞≈≈–Ú 
#include<stdio.h>
int a[10]={5,8,12,4,6,7,8,9,12,11};
int b[100]={0};
int main()
{
	for(int i=0;i<10;i++)
	{
		b[a[i]]++;
	}
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<b[i];j++)
		{
			printf("%d,",i);
		}
	}
}
