#include<stdio.h>
#include<algorithm>
using namespace std;
int a[5]={5,2,4,3,1};
typedef int* P;
P p[5];
int cmp(P a,P b)
{
	if(*(a)<*(b)) return 1;
	else return 0;
}

int main()
{
	for(int i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
		p[i]=&a[i];		
	}
	sort(p,p+5,cmp);
	for(int i=0;i<5;i++)
	{
		printf("%d,%d\n",a[i],*(p[i]));
	}
	
}


