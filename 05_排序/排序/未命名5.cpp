//ц╟ещ 
#include<stdio.h>
int a[5]={4,5,3,1,2};
int main()
{
	int temp;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];a[j]=a[j+1];a[j+1]=temp;	
			}
		}
	}
	
	for(int i=0;i<5;i++)
	{
		printf("%d,",a[i]);
	}
}
