#include<stdio.h>
#define Max(x,y) (x>y?x:y)
int value[10]={0,1,2,3,4,5,6,7,8,9};
struct Node{
	int l,r;
	int max;
	int tag;
};
Node tree[10<<1];

void build(int i,int l,int r)
{
	tree[i].l=l;tree[i].r=r;
	if(l==r)
	{
		tree[i].max=value[l];
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tree[i].max=Max(tree[i<<1].max,tree[i<<1|1].max);
}
//单点修改，要修改value[dis]=v 
void editNode(int i,int dis,int v)
{
	if(tree[i].l==tree[i].r)
	{
		tree[i].max=v;
		return;	
	} 
	if(dis<=tree[i<<1].r) editNode(i<<1,dis,v);
	else editNode(i<<1|1,dis,v);
	tree[i].max=Max(tree[i<<1].max,tree[i<<1|1].max);
}
//区间修改
void editSequence(int i,int l,int r,int v)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].max+=v;
		tree[i].tag+=v;
		return;
	}
	if(l<=tree[i<<1].r) editSequence(i<<1,l,r,v);
	if(r>=tree[i<<1|1].l) editSequence(i<<1|1,l,r,v);
	tree[i].max=Max(tree[i<<1].max,tree[i<<1|1].max);
 } 
//区间查询
int query(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		return tree[i].max;
	}
	if(tree[i].r<l||tree[i].l>r) return 0;
	int max=0;
	if(l<=tree[i<<1].r) max=Max(max,query(i<<1,l,r));
	if(r>=tree[i<<1|1].l) max=Max(max,query(i<<1|1,l,r));
	return max;
 } 
//带tag标记的区间查询
int querySequence(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		return tree[i].max;
	}
	if(tree[i].l>r||tree[i].r<l) return 0;
	int left=i<<1,right=i<<1|1;
	//准备往下推
	if(tree[i].tag!=0)
	{
		
		tree[left].tag+=tree[i].tag;
		tree[left].max+=tree[i].tag;
		tree[right].tag+=tree[i].tag;
		tree[right].max+=tree[i].tag;
		tree[i].tag=0;	
	} 
	int max=0;
	if(l<=tree[left].r) max=Max(max,querySequence(left,l,r));
	if(r>=tree[right].l) max=Max(max,querySequence(right,l,r));
	return max;
} 

int main()
{
	build(1,1,9);
		//区间查询 
	printf("%d\n",query(1,3,5));
	//单点修改 
	editNode(1,3,12);
	//修改后的区间查询 
	printf("%d\n",query(1,3,5));
		//区间修改
	editSequence(1,1,6,1);
	editSequence(1,4,8,2);
	//Debug();
	//区间查询
	printf("%d\n",querySequence(1,3,6));
}


