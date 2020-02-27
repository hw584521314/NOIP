//走迷宫，DFS，有无解 

#include<stdio.h>

int a[5][5]={
{0,1,0,0,1},
{0,0,0,1,0},
{1,1,0,0,0},
{0,0,0,1,0},
{0,1,1,0,0}
};
int StartX=0;
int StartY=0;
int TargetX=4;
int TargetY=4;

int dir[]={-1,1,-2,2}; 
int dirx[]={-1,1,0,0};
int diry[]={0,0,-1,1};
//-1,1,-2,2分别表示上下左右 
//x代表行，y代表列 
int f(int x,int y,int source)
{
	if(x<0||x>4||y<0||y>4)
	{
		return 0;
	}
	if(a[x][y]==1)
	{
		return 0;
	}
	if(x==TargetX&&y==TargetY)
	{
		return 1;
	}
	//四个方向 
	for(int i=0;i<4;i++)
	{
		if(dir[i]!=source*-1)
		{
			if(f(x+dirx[i],y+diry[i],dir[i])==1)
			{
				return 1;
			}
		}
	}
	return 0;
} 

int main()
{
	if(f(0,0,0)==1)
	{
		printf("yes"); 
	}
	else
	{
		printf("no");
	}
}
