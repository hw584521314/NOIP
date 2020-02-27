#include<stdio.h>
#include<algorithm>
using namespace std;
int a[5]={5,2,4,3,1};

bool cmp(int x,int y)
{
	if(a[x]<a[y]) return true;
	else return false;
}
int main()
{
	int b[5]={0,1,2,3,4};
	sort(b,b+5,cmp); 
	for(int i=0;i<5;i++)
	{
		printf("%d,%d\n",b[i],a[b[i]]);
	}
 } 
