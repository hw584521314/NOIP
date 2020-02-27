#include<stdio.h>
int result;
int a[8]={1,3,1,5,9,7,4,8};
void f(int n,int pre,int count)
{
	if(n==8)
	{
		if(count>result)
		{
			result=count;
		}
		return;
	}
	if(a[n]>=pre)
		f(n+1,a[n],count+1);
	//不管大和小，都来一遍 
	f(n+1,pre,count);

}
int main()
{
	
	f(0,a[0],0);
	printf("%d",result);
}



