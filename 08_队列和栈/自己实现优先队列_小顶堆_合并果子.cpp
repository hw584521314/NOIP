#include<stdio.h>
#include<iostream>
using namespace std;
int hp[20000];
int last=1;//����0��Ԫ�ز��ã���1��Ԫ�ؿ�ʼʹ�� 
void push(int a)
{
	hp[last]=a;
	int parent=last/2,child=last;
	while(parent>0&&hp[parent]>a)
	{
		//�ϸ� 
		//ֱ�Ӱ�ֵ�����������������Ż����ɣ������˽��� 
		hp[child]=hp[parent] ;
		child=parent;
		parent=child/2;
	}
	//���ֵ 
	hp[child]=a;
	last++;
}
int front()
{
	return hp[1];
}
//�ù��ܻᱻ���ã����Է�װ�¡� 
void ShiftDown(int begin)
{
	int parent=begin,left,right;
	int child=parent<<1;//��ߺ��� 
	int temp=hp[parent];//��ʱ�����£����ֵ 
	while(child<last)
	{
		//����Һ��ӱ����Ӹ�������µ�ǰ����ָ�룬��֤��ǰ����ָ��ָ��
		//�������Һ����нϴ���Ǹ� 
		//����ȷ�������Һ��� 
		if(child+1<last&&hp[child+1]<hp[child])
		{
			child++;
		}
		//���temp�Ѿ��ȵ�ǰ���ĺ��Ӹ�����ǰ�����������Ҫ����ĵط� 
		if(temp<=hp[child])
		{
			break;
		}
		//�³�������ע�⣬ֻ��Ҫ�򵥵İѺ��ӵ�ֵ��ֵ����ǰ���ڵ㼴�ɣ�û��Ҫ����ֵ
		//��Ϊ���ǵ�tempʼ�վ������ǵ��³���ֵ�� 
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
//�ѻ�������ֱ���������Ͻ��в��� 
void Heapify(int *a,int size)
{
	//�����ã�����ʼ����last 
	memcpy(hp+1,a,size*sizeof(int)); 
	last=size+1;
	//��ʼ���� 
	int l=size/2;//�����һ����Ҷ�ӽڵ㿪ʼ
	for(int i=l;i>=1;i--)
	{
		ShiftDown(i);	
	} 
} 
//���¶Ѷ�Ԫ�� 
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
