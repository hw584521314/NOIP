#include<stdio.h>
int a[10]={1,2,3,4,5,4,7,8,9,0};//{6,2,4,3,6,9,8,7,1,5};
void swap(int &a,int &b)
{
	int c;
	c=a;a=b;b=c;
}
void qsort(int left,int right)
{
	if(left>=right) return;
	int tl=left,tr=right;
	int f=a[tl];
	bool isLeft=true;//用来跟踪当前的这个基准值在左侧还是在右侧，决定后面的移位 
	//a[tl]和a[tr]中一定有一个一直保存着标兵，其实是标兵在和不同的数之间进行移动。
	
	while(tl<tr)
	{
		while(a[tl]<f) tl++;
		while(a[tr]>f) tr--;
		//移动的最终的结果，肯定是tl==tr，也就是会重合 
		//所以这里加这个判断，这样就一定是tl==tr时是循环结束条件 
		if(tl>=tr) break; 
		swap(a[tl],a[tr]);
		if(isLeft)
		{//标兵在左侧，则交换后变到右侧，这里应该左侧自增。右侧不变 
			tl++;
		}
		else
		{
			tr--;
		}
		isLeft=!isLeft;
	}
	if(tl>tr)
	{
		printf("impossible by analyze\n"); 
	 } 
	//循环完毕时只有一种情况：tl==tr
	//标兵元素就可能在tl位置 
	qsort(left,tl-1);
	qsort(tl+1,right);	
} 

int main()
{
	qsort(0,9);
	for(int i=0;i<10;i++)
	{
		printf("%d,",a[i]);
	}
}
