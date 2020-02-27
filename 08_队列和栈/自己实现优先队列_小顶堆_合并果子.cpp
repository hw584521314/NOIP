#include<stdio.h>
#include<iostream>
using namespace std;
int hp[20000];
int last=1;//数组0号元素不用，从1号元素开始使用 
void push(int a)
{
	hp[last]=a;
	int parent=last/2,child=last;
	while(parent>0&&hp[parent]>a)
	{
		//上浮 
		//直接把值给降下来。这里是优化技巧，避免了交换 
		hp[child]=hp[parent] ;
		child=parent;
		parent=child/2;
	}
	//最后赋值 
	hp[child]=a;
	last++;
}
int front()
{
	return hp[1];
}
//该功能会被复用，所以封装下。 
void ShiftDown(int begin)
{
	int parent=begin,left,right;
	int child=parent<<1;//左边孩子 
	int temp=hp[parent];//临时保存下，最后赋值 
	while(child<last)
	{
		//如果右孩子比左孩子更大，则更新当前孩子指针，保证当前孩子指针指向
		//的是左右孩子中较大的那个 
		//首先确认下有右孩子 
		if(child+1<last&&hp[child+1]<hp[child])
		{
			child++;
		}
		//如果temp已经比当前最大的孩子更大，则当前这个索引就是要插入的地方 
		if(temp<=hp[child])
		{
			break;
		}
		//下沉。这里注意，只需要简单的把孩子的值赋值给当前父节点即可，没必要交换值
		//因为我们的temp始终就是我们的下沉的值。 
		hp[parent]=hp[child];
		parent=child;
		child=parent<<1;		
	}
	hp[parent]=temp; 
}
void pop()
{
	hp[1]=hp[last-1];	
	ShiftDown(1); 
	last--;
}
//堆化，这里直接在数组上进行操做 
void Heapify(int *a,int size)
{
	//拷贝好，并初始化好last 
	memcpy(hp+1,a,size*sizeof(int)); 
	last=size+1;
	//开始下移 
	int l=size/2;//从最后一个非叶子节点开始
	for(int i=l;i>=1;i--)
	{
		ShiftDown(i);	
	} 
} 
//更新堆顶元素 
void Replace(int a)
{
	hp[1]=a;
	ShiftDown(1);
} 
int a[20000];
int main()
{
	
	//int a[5]={1,6,3,7,2};
	
	/*for(int i=0;i<5;i++)
	{
		push(a[i]);
	}*/
	/*Heapify(a,5);
	push(10); 
	for(int i=0;last>1;i++)
	{
		printf("%d,",front());
		pop();
	}
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	Heapify(a,n);
	int s=0,t1,t2;
	for(int i=0;i<n-1;i++)
	{
		t1=front();
		pop();
		t2=front();
		pop();
		s+=t1+t2;
		push(t1+t2);
	}
	printf("%d",s);
	
}
