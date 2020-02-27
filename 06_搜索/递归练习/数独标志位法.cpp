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
int amid[9][9]={
0,0,0,1,1,1,2,2,2,
0,0,0,1,1,1,2,2,2,
0,0,0,1,1,1,2,2,2,

3,3,3,4,4,4,5,5,5,
3,3,3,4,4,4,5,5,5,
3,3,3,4,4,4,5,5,5,

6,6,6,7,7,7,8,8,8,
6,6,6,7,7,7,8,8,8,
6,6,6,7,7,7,8,8,8,
}; 
unsigned int row[9]={0};//行标记  数组。每一个代表某一行 数1~9是否已经有了，有了相应的位置1，否则为0 
unsigned int col[9]={0}; 
unsigned int mid[9]={0};//小区间 数组，每一个代表3*3区间数1~9是否已经有了。 
bool v(int i,int j,int value)
{
	//判断行是否可行 
	if(((1<<value)&row[i])!=0) return false;
	//判断列是否可行 
	if(((1<<value)&col[j])!=0) return false;
	//判断所在小9格是否可行 
	if(((1<<value)&mid[amid[i][j]])!=0) return false;
	
	return true; 
}
//设置value对应的标志位为1 
void fillValue(int i,int j,int value)
{
	 row[i]=row[i]|(1<<value);
	 col[j]=col[j]|(1<<value);
	 mid[amid[i][j]]=mid[amid[i][j]]|(1<<value);
}
//清除value对应的标志位，置0. 
void clearValue(int i,int j,int value)
{
	row[i]=row[i]&~(1<<value);
	 col[j]=col[j]&~(1<<value);
	 mid[amid[i][j]]=mid[amid[i][j]]&~(1<<value);
}
//把二维数组转为1维访问 
bool fill(int idx)
{
	int j=idx%9;//得到行 
	int i=idx/9;//列 
	//填写完毕， 能运行到这里，说明前面都为true，因为只要有false就要回滚。 
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
	int flag=0; 
	//标志位：如果该位置1~9一个数都不能填，则返回false。否则，返回true。
	//要对1~9的每一个数都进行遍历，只要能填就继续往前滚动。 
	for(int n=1;n<=9;n++)
	{
		if(v(i,j,n)==true)		
		{
			a[i][j]=n;	
			fillValue(i,j,n);	
			fill(idx+1);//这个点可以填，就继续往前滚动，这时返回值不重要。 
			a[i][j]=0;//放弃该数
			clearValue(i,j,n); 
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
	//初始化标记序列
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			fillValue(i,j,a[i][j]); 
		}
	 } 
	fill(0);
}

