#include<stdio.h>
#include<iostream>
using namespace std;
int a[6]={3,4,3,34,3,3};
int sum[6];
int m[6][6];
int minn[6][6];
int main()
{
	int s=0;
	for(int i=0;i<6;i++)
	{
		s+=a[i];
		sum[i]=s;
	}
	for(int i=0;i<6-1;i++)
	{
		int hang=0;
		for(int lie=i+1;lie<6;lie++,hang++)
		{
			int t=sum[lie]-sum[hang]+a[hang];
			minn[hang][lie]=10000;
			for(int k=hang;k<lie;k++)
			{
				m[hang][lie]=max(m[hang][k]+m[k+1][lie]+t,m[hang][lie]);
				minn[hang][lie]=min(minn[hang][k]+minn[k+1][lie]+t,minn[hang][lie]);
			}
			
		}
	}
	printf("%d,%d",m[0][5],minn[0][5]);
}
