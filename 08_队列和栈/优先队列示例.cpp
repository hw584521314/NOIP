#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
//�������
priority_queue <int,vector<int>,greater<int> > p;
//�������
priority_queue <int,vector<int>,less<int> > q;
//Ĭ�ϴ󶥶� 
priority_queue <int> r ;
int main()
{
	p.push(1);
	p.push(2);
	p.push(3);
	while(!p.empty())
	{
		cout<<p.top();
		p.pop();
	}
	printf("\n");
	q.push(1);
	q.push(2);
	q.push(3);
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	printf("\n");
	r.push(1);
	r.push(2);
	r.push(3);
	while(!r.empty())
	{
		cout<<r.top();
		r.pop();
	}
}


