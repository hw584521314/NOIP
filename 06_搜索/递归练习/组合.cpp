#include <iostream>
using namespace std;
//a为存放待组合的数值，b为用于暂存的数组
//n，m代表从n中取出m个数的组合 
// M=m M用于输出 
int a[]={0,1,2,3,4};
int b[5];
void c(int n, int m,const int M)
{
	if(m==0)
	{
		for(int i =0 ; i<M;i++)
			printf("%d",b[i]);
		printf("\n");
		return;
	}	
	for (int i =n;i>=m;i--)
	{
		//确定我的第m项的值 
		b[m-1]=a[i-1];	
		//由于确定了当前位置的值
		//则下次递归c(n-1,m-1) 
		c(i-1,m-1,M);
	}	
}
 
int main ()
{
	c(5,3,3); 
	return 0;
} 

