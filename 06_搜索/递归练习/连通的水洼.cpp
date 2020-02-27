#include<stdio.h>
const int N=10;
const int M=12;
char a[N][M+1]=
{
	"W........WW.",
	".WWW.....WWW",
	"....WW...WW.",
	".........WW.",
	".........W..",
	"..W......W..",
	".W.W.....WW.",
	"W.W.W.....W.",
	".W.W......W.",
	"..W.......W."
};
void f(int i,int j)
{
	if(i<0||i>=N) return;
	if(j<0||j>=M) return;
	for(int x=-1;x<=1;x++)
	{
		for(int y=-1;y<=1;y++)
		{
			if(a[i+x][j+y]=='W')
			{
				a[i+x][j+y]='.';
				f(i+x,j+y);
			}
				
		}
	}
}

int main()
{
	int count=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(a[i][j]=='W')
			{
				f(i,j);
				count++;
			}
		}
	}
	printf("%d",count);
}

