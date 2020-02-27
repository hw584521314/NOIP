#include<stdio.h>
struct Node{
	int value;
	Node *next;
};

Node *head=NULL;
int length=0;
void insert(Node *n)
{
	length++;
	if(head==NULL)
	{
		n->next=NULL;
		head=n;
		return;
	}
	n->next=head;
	head=n;
}

Node *get(int n)
{
	if(n>length)
	{
		return NULL;
	}
	int i=0;
	Node *it=head;
	while(i++<n)
	{
		it=it->next;
	}
	return it;
}

Node* del(int n)
{
	if(n>length)
	{
		return NULL;
	}

	Node *pre=NULL;
	Node *it=head;
	if(n==0)
	{
		head=head->next;
		length--;
		return it;
	}
	int i=0;
	while(i++<n)
	{
		pre=it;
		it=it->next; 
	} 
	pre->next=it->next;
	length--;
	return it;
}

bool del(Node *n)
{
	Node *pre=NULL;
	Node *it=head;
	if(n==head)
	{		
		head=NULL;
		length=0;
		return true;
	}
	int i=0; 
	while(i++<length&&it!=n)
	{
		pre=it;
		it=it->next; 
	} 
	pre->next=it->next;
	length--;
	return true; 
}

int main()
{
	//Node* n=new Node();
	Node a[10];
	a[0].value=1;
	//n->value=1;
	insert(&a[0]);
} 
