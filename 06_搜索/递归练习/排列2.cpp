#include<stdio.h>
/*
全排列，这里使用a的前N项保存要输出的结果。每次取出来的数放入a的前面。 
*/

char a[5]="ABCD";
int M=4;
int N=3;

void swap(char &a,char &b)
{
	char c;
	c=a;a=b;b=c;
}
void q(int m,int n)
{
	if(n==0)
	{
		for(int i=0;i<N;i++)
		{
			printf("%c",a[i]);
		}
		printf("\n");return;
	}
	//依次从生下的m~M个数中 ，任选一个数，放入第m项，然后继续求剩下数中取n-1项。 
	for(int i=m;i<M;i++)
	{
		swap(a[m],a[i]);//这里把选出来的项放入m位置 
		q(m+1,n-1);//特别注意这里，由于已经交换过位置到m项了，从剩下的m+1~M中取值
		//这里和组合是不同的，组合使用的是i+1.因为思路是有区别的！ 
		swap(a[m],a[i]);//换回来，保证下一次又从以前的状态开始，避免出现重复项。 
	}
}

int main()
{
	q(0,N);
	return 0;
} 



 
