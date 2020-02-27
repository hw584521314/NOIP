#include<stdio.h>
int n=5;
int a[10][10]={
{7},
{3,8},
{8,1,0},
{2,7,4,4},
{4,5,2,6,5}};
int result=0;
void f(int x,int y,int total)
{
	if(x<0||y<0) return;
	if(x==0&&y==0)
	{
		total=total+a[0][0]; 
		if(total>result)
		{
			result=total;
		}
		return;
	}
	total+=a[x][y];
	f(x-1,y,total);
	f(x-1,y-1,total);
 } 
 
 int main()
 {
 	for(int i=0;i<n;i++)
 	{
 		f(4,i,0);
	}
	printf("%d",result);
 }
