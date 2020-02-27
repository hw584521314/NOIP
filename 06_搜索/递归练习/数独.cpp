#include<stdio.h>


int a[9][9]=
{
	{9,0,0, 2,0,0, 0,0,0},
	{8,0,0, 3,0,0, 0,0,4},
	{0,3,5, 9,0,6, 0,0,0},
	
	{0,0,0, 0,0,0, 8,7,0},
	{0,6,0, 0,0,0, 0,3,0},
	{0,5,7, 0,0,0, 0,0,0},
	
	{0,0,0, 8,0,3, 6,4,0},
	{3,0,0, 0,0,2, 0,0,5},
	{0,0,0, 0,0,1, 0,0,2}
};
struct se{
	int start,end;
};
se axy[9]={{0,2},{0,2},{0,2},{3,5},{3,5},{3,5},{6,8},{6,8},{6,8}}; 
 
bool v(int i,int j,int value)
{
	//判断行是否可行 
	for(int x=0;x<9;x++)
	{
		if(a[i][x]==value)
		{
			return false;
		}
	}
	//判断列是否可行 
	for(int x=0;x<9;x++)
	{
		if(a[x][j]==value)
		{
			return false;
		}
	}
	//判断所在小9格是否可行 
	int startx=axy[i].start;
	int endx=axy[i].end;
	int starty=axy[j].start; 
	int endy=axy[j].end;
	for(int x=startx;x<=endx;x++)
	{
		for(int y=starty;y<=endy;y++)
		{
			if(a[x][y]==value)
			{
				return false;
			}
		}
	}
	return true; 
}

bool fill(int idx)
{
	int j=idx%9;
	int i=idx/9;
	//填写完毕， 
	if(idx==81)
	{
		//打印整个结果
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		 } 
		return true; 
	}
	//开始逐个尝试
	//如果当前位置已经有值，直接下一轮判断 
	if(a[i][j]!=0)
	{
		return fill(idx+1);
	} 
	//如果没有值，则填值
	//标志位：如果该位置1~9一个数都不能填，则返回false。否则，返回true。
	//要对1~9的每一个数都进行遍历，只要能填就继续往前滚动。 
	int flag=0; 
	for(int n=1;n<=9;n++)
	{
		if(v(i,j,n)==true)		
		{
			a[i][j]=n;		
			fill(idx+1);
			a[i][j]=0;//放弃该数 
			flag=1;
		}
	}
	if(flag==1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

int main()
{
	fill(0);
}

