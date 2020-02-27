#include <iostream>

using namespace std;

struct Node{
int value;
};
//下面是队列实现
const int queueSize=3;
Node _allNodes[queueSize];
int head;
int tail;
int push(Node &n)
{
    if((tail+1)%queueSize==head)
    {
        cout<<"queue full"<<endl;
        return -1;
    }
    _allNodes[tail].value=n.value;
    return tail=(tail+1)%queueSize;
}
Node* front()
{
    return &_allNodes[head];
}
int pop()
{
    if(head==tail)
    {
        cout<<"queue empty"<<endl;
        return -1;
    }
    return head=(head+1)%queueSize;
}
int empty()
{
    if(head==tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//队列实现结束
int main()
{
    if(empty())
    {
        cout<<"empty"<<endl;
    }
    Node a;
    a.value=10;
    push(a);
    a.value=20;
    push(a);

    Node *p;
    while(!empty())
    {
        p=front();
        pop();
        cout<<p->value<<endl;
    }
    a.value=30;
    push(a);
    a.value=40;
    push(a);
    while(!empty())
    {
        p=front();
        pop();
        cout<<p->value<<endl;
    }
    a.value=50;
    push(a);
    p=front();
    pop();
    cout<<p->value<<endl;
    a.value=60;
    push(a);
    p=front();
    pop();
    cout<<p->value<<endl;
    pop();
    return 0;
}
