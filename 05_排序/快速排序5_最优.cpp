#include<stdio.h>
#include<iostream>
using namespace std;
int A[1000001]={6,2,4,3,6,9,8,7,1,5};
//{1,2,3,4,5,6,7,8,9,10};
//{6,2,4,3,6,9,8,7,1,5};
int N;
//针对已有序数组的更优化方式是使用中间的数作为中位数 
void quickSort(int l,int r)
{
	if(l>=r) return;
	int m=A[(l+r)/2];	
	int lt=l,rt=r;
	while(lt<=rt)
	{
		//这里没有==符号，是为了使得左右两边能在m处停下来，这样在后续的移动中，m的值会随着一起移动
		//而且仔细思考，会发现一旦不管是左边还是右边一旦指向了m值，则m就会参与后续的每一次交换？：不对 
		//但每一次交换后，通过swap后的lt++和rt--,又不会指向m值。那问题变为最终的lt和rt并不会在m附近 
		//确认了，确实是这样，例如这次第一轮完毕后,m=6,为:5 2 4 3 1 9 8 7 6 6. lt=5, rt=4
		//但不管何如，实现了lt和rt把整个数据分成了小于6和大于6. 
		while(A[rt]>m) rt--;
		while(A[lt]<m) lt++;
		
		if(lt<=rt)
		{
			//==也执行一遍主要是为了执行下面的lt++和rt-- 
			swap(A[lt],A[rt]);	
			lt++;
			rt--;
		}				
	}
	quickSort(l,rt);
	quickSort(lt,r);
}

int main()
{
	N=10;
	/*scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	*/
	quickSort(0,N-1);
	for(int i=0;i<N;i++)
	{
		printf("%d ",A[i]);
	}
}
