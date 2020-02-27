#include<stdio.h>
//这里的线段树从1开始，这样左右孩子不受0的影响 
//原始数据 
int value[10]={0,1,2,3,4,5,6,7,8,9};
//定义点 
struct Point{
	int l,r;
	int sum;
	int tag;
};
//定义线段树 
Point tree[10<<2];

//从原始数据构造线段树，完成线段树的初始化。这里使用左右闭包[left,right] 
void build(int i,int left,int right)
{
	tree[i].l=left;
	tree[i].r=right;
	if(left==right)
	{
		tree[i].sum=value[left];
		return;
	}
	int mid=(left+right)>>1;
	build(i<<1,left,mid);//左孩子 进行构造 
	build(i<<1|1,mid+1,right);//右孩子进行构造 
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;//左右孩子完成构造后，完成父节点的赋值 
}
//点更新:value的第dis个值更新为v ，i是便于递归，调用时，都是从i=1开始 
void editPoint(int i,int dis,int v)
{
	//找到了最终的那个叶子节点，则更新 
	if(tree[i].l==tree[i].r)
	{
		tree[i].sum=v;
		return;
	}
	//如果dis为 左边部分，则更新左边，否则更新右边。由于现在是闭包，可以取到等号 
	if(dis<=tree[i<<1].r) editPoint(i<<1,dis,v);
	else editPoint(i<<1|1,dis,v);
	//叶子更新完毕的同时，注意更新下父节点。 
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
}
//区间查询，i是作为递归的条件，调用时，始终使用i=0来调用。l是左区间下标，r是右区间下标。 
int query(int i,int l,int r)
{
	//这个节点完全处于待求解区间内，则直接返回该节点的值 
	if(tree[i].l>=l&&tree[i].r<=r) return tree[i].sum;	
	if(tree[i].r<l||tree[i].l>r) return 0;//这个节点和区间没有任何交集 
	int sum=0;
	//左孩子区间部分覆盖区间，则继续从左孩子中取值，左孙子的左孩子可能就和区间没有交集了，但可能孙子的右孩子和区间有交集 
	if(l<=tree[i<<1].r) 
		sum+=query(i<<1,l,r);
	if(r>=tree[i<<1|1].l)
		sum+=query(i<<1|1,l,r);
	return sum;
} 
//区间修改:这里为加上某个值v，另外还有一种就是整个区间赋值为另一个值 
//要使用优化技巧：lazyTag：更新时，并不真正扩展，除非查询时，需要往下分支时，才把标记往下扩展。保证最低限度的向上有效 
void editSequence(int i,int l,int r,int v) 
{
	if(tree[i].l>=l&&tree[i].r<=r) 
	{
		tree[i].sum+=v*(tree[i].r-tree[i].l+1);//这里先做了 
		tree[i].tag+=v;//这里使用+=，就表示支持多次更新，一次查询，积累每次更新的效果 
		return;
	}
	if(tree[i].r<l||tree[i].l>r) return;
	if(l<=tree[i<<1].r) editSequence(i<<1,l,r,v);
	if(r>=tree[i<<1|1].l) editSequence(i<<1|1,l,r,v);
	//这里实现向上保持一致，但底部完全是通过tag，并没有完全更新所有的底部的sum
	//在后面查询到底部的时候，再实现对应底部的更新 
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
	return;
}
int querySequence(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r) 
		return tree[i].sum;//区间更新时已经算过 
	if(tree[i].r<l||tree[i].l>r) 
		return 0;
	//准备下推lazyTag，固化当前，清空tag 
	if(tree[i].tag!=0)
	{
		tree[i<<1].tag+=tree[i].tag;//注意+=的使用 
		tree[i<<1|1].tag+=tree[i].tag;
		//下推时，同时更新sum的值，因为没有其他机会可以更新sum的值。下推时，向上来说，上半部分是不同改动的。 
		tree[i<<1].sum  += (tree[i<<1].r-tree[i<<1].l+1)*tree[i].tag;
		tree[i<<1|1].sum+= (tree[i<<1|1].r-tree[i<<1|1].l+1)*tree[i].tag;
		tree[i].tag=0;
	}
	
	//求值 
	int sum=0;
	if(l<=tree[i<<1].r)
	{
		sum+=querySequence(i<<1,l,r);
	}
	if(r>=tree[i<<1|1].l)
	{
		sum+=querySequence(i<<1|1,l,r);
	}
	return sum;
}
void Debug()
{
	int i=1;
	int line=1;
	int lineNum=0;
	while(tree[i].l!=0)
	{
		printf("(l=%d,r=%d,t=%d,s=%d)  ",tree[i].l,tree[i].r,tree[i].tag,tree[i].sum);
		i++;
		lineNum++;
		if(lineNum==line)
		{
			printf("\n");
			line<<=1;
			lineNum=0;
		}
	}
}
int main()
{
	//建树 
	build(1,1,9);
	//区间查询 
	//printf("%d\n",query(1,3,5));
	//单点修改 
	//editPoint(1,3,5);
	//修改后的区间查询 
	//printf("%d\n",query(1,3,5));
	//区间修改
	editSequence(1,1,6,1);
	editSequence(1,4,8,2);
	//Debug();
	//区间查询
	printf("%d\n",querySequence(1,3,6)); 
}
