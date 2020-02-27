//树的宽度优先搜索 
#include<bits\stdc++.h>
using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};

queue<Node*> q;
Node *root;
void my();
int main()
{
	Node *temp=new Node();
	
	temp->value=1;
	root=temp;
	//左边 
	Node *temp1=new Node();
	temp1->value=2;
	Node *temp2=new Node();
	temp2->value=4;
	temp2->left=NULL;
	temp2->right=NULL;
	temp1->left=NULL;
	temp1->right=temp2;
	
	temp->left=temp1;
	//右边 
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
	//构造完毕
	q.push(root);
	my();
	printf("\n"); 
	
}

void my()
{
	Node *temp;
	while(q.size()!=0)
	{
		temp=q.front();
		
		printf("%d,",temp->value);
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
		q.pop();
	}
	
}
