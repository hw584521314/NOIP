#include<queue>
#include<stdio.h>
using namespace std;
//priority_queue<int>  q;
//priority_queue<int,vector<int>,greater<int> >q;
struct Node{
	int value;
	//����������ڶ�β���ж�parent<child���������ֵΪtrue���򽻻������򲻽����� 
	bool operator<(const Node &b) const
	{
		if(value>b.value) return true;
		return false;
	}
};
priority_queue<Node>  q;
int main()
{
	Node a[5]={1,6,3,7,2};
	
	for(int i=0;i<5;i++)
	{
		q.push(a[i]);
	}
	Node t={10};
	q.push(t); 
	for(;q.size();)
	{
		printf("%d,",q.top().value);
		q.pop();
	}
}
