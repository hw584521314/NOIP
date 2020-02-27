//部分和，最少的数构成解
/*思路，其实如果从末尾开始往前递归的话，我们只需要保证数组从小到大排序
然后使用DFS，求出第一组解即可 
*/ 
#include<bits\stdc++.h>
using namespace std;
int a[6]={5,4,2,9,11,8};
int b[6]={0}; 

int f(int s,int x,int l)
{
	if(s<0) 
	{
		return 0;
	}
	else if(s==0)
	{	
		for(int i=0;i<l;i++)
		{
			printf("%d,",b[i]);
		}
		printf("\n");	
		return 1;
	}
	else if(x<0)
	{//这个必须放在后面，因为有可能x<0时，s刚好等于0 
		return 0;
	}

	//若选择
	b[l]=a[x];
	if(f(s-a[x],x-1,l+1)==1)
	{
		return 1;
	}
	b[l]=0;
	//不选择 
	return f(s,x-1,l);

}

int main()
{
	//排序
	sort(a,a+6); 
	int b=20;
	f(b,5,0);
			
}  
