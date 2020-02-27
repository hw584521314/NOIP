#include<stdio.h>
struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *root;
void forward( Node *t);
void middle(Node *t);
void back(Node *t);
int main()
{
	Node *temp=new Node();
	
	temp->value=1;
	root=temp;
	//×ó±ß 
	Node *temp1=new Node();
	temp1->value=2;
	Node *temp2=new Node();
	temp2->value=4;
	temp2->left=NULL;
	temp2->right=NULL;
	temp1->left=NULL;
	temp1->right=temp2;
	
	temp->left=temp1;
	//ÓÒ±ß 
	temp1=new Node();
	temp1->value=3;
	temp2=new Node();
	temp2->value=5;
	temp2->left=NULL;
	temp2->right=NULL; 
	temp1->left=temp2;
	
	temp2=new Node();
	temp2->value=6;
	temp2->left=NULL;
	temp2->right=NULL; 
	temp1->right=temp2;
	
	temp->right=temp1;
	//¹¹ÔìÍê±Ï
	 //forward(root);
	 middle(root);
	 //back(root);
	 printf("\n"); 
	
}


void forward( Node *t)
{
	if(t==NULL)
	{
		return;
	}
	printf("%d,",t->value);
	forward(t->left);
	forward(t->right);
}

void middle(Node *t)
{
	if(t==NULL)
	{
		return;
	}	
	middle(t->left);
	printf("%d,",t->value);
	middle(t->right);
}

void back(Node *t)
{
	if(t==NULL)
	{
		return;
	}	
	back(t->left);	
	back(t->right);
	printf("%d,",t->value);
}


