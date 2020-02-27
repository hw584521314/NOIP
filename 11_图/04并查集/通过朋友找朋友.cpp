/*输入n组 1~10相互关系-朋友，
最后输入一组数  a  b， 判断 ab是否是一伙的
一伙的输出YES，否则NO 
*/
#include<stdio.h>

int a[100];
//查找boss 
int find(int x)
{
	if(x==a[x]) return x;
	return a[x]=find(a[x]);//扁平化 
}
//两个团队的boss进行合并 
void join(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y) a[x]=y;
}

int main()
{
	int n;
	scanf("%d",&n);
	//初始化
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	//读入关系定义
	scanf("%d",&n);
	int x,y;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		join(x,y);
	} 
	//判断是否是同一组织下
	scanf("%d%d",&x,&y);
	x=find(x);
	y=find(y);
	if(x==y)
	{
		return "YES";
	} 
	else
	{
		return "NO";
	}
 } 



