#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
	int value;
};
//最需要好好理解的就是这个数据结构，前面m个代表所属集合。重点是后面m个表示的是敌人的索引（而非敌人的值）
//表明的是f[1+m]=2，表示的是1号的敌人是2号，至于2号属于哪个阵营，是靠find函数来实现的。和2号的boss也好无关系。 
int f[100];
node nodes[100];
bool sortFunc(node a,node b)
{
	if(a.value>b.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//不停往上找支线boss，同时更新f[x]的值 
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
//建立连接，这种方式建立的链接是随机的。无法确认谁在谁的下面，boss是谁，但不重要，只要保证在一个集合 
void join(int x,int y)                     
{

    int fx=find(x), fy=find(f[y]);             
    if(fx != fy) 
	{//建立连接 
		f[fx]=fy;
	}                           
         
		                      
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		f[i]=i;
	}
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&nodes[i].x,&nodes[i].y,&nodes[i].value);
	}
	sort(nodes,nodes+n,sortFunc);
	int idx=0;
	int a,b;
	while(1)
	{
		a=find(nodes[idx].x);	//找第一个的boss 
		b=find(nodes[idx].y);	//找第二个的boss 
		if(a==b)//无法拆分了，退出 
		{
			break;
		}
		if(f[nodes[idx].x+m]==0)
		{
			f[nodes[idx].x+m]=nodes[idx].y;
		}
		else
		{
				//使用boss更新当前项，类似于在归并操作 
			join(nodes[idx].y,f[nodes[idx].x+m]);
		}
		if(f[nodes[idx].y+m]==0)
		{
			f[nodes[idx].y+m]=nodes[idx].x;
		}
		else
		{
			join(nodes[idx].x,f[nodes[idx].y+m]); 
		}		
		
		idx++;
		
	} 
	printf("%d",nodes[idx].value);
	 
}

