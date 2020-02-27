#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
struct goods{
int v;
int f;
int pre;
};
int Zu[61];

int maxZu=0;
goods allGoods[61];

struct State
{
    int zu;//��ʾ�ڼ���
    int f;//��ʾ����
    int v;//��״̬���Ž�
};
queue<State> q;
int maxx=0;
int nextZu(int curZu)
{
    for(int i=curZu+1;i<=maxZu;i++)
    {
        if(Zu[i]!=0) return i;
    }
    return maxZu+10;
}
void Func()
{
    State s,t;
    int next;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        if(s.zu>maxZu)
        {
            if(s.v>maxx) maxx=s.v;
            continue;
        }
        next=nextZu(s.zu);
        //ѡ������
        if(s.f>=allGoods[s.zu].f)
        {
            //��ѡ����
            t.zu=next;
            t.f=s.f-allGoods[s.zu].f;
            t.v=s.v+allGoods[s.zu].v;
            q.push(t);
            //û�и���ֱ������
            if(Zu[s.zu]!=0)
            {
                //��ѡһ��
                int tf=0,tv=0;
                for(int k=Zu[s.zu];k!=s.zu;k=allGoods[k].pre)
                {
                    if(s.f-allGoods[s.zu].f-allGoods[k].f>=0)
                    {
                        t.f=s.f-allGoods[s.zu].f-allGoods[k].f;
                        t.v=s.v+allGoods[s.zu].v+allGoods[k].v;
                        q.push(t);
                    }
                    tf+=allGoods[k].f;
                    tv+=allGoods[k].v;
                }
                //������ѡ
                if(s.f-allGoods[s.zu].f-tf>=0)
                {
                    t.f=s.f-allGoods[s.zu].f-tf;
                    t.v=s.v+allGoods[s.zu].v+tv;
                    q.push(t);
                }
            }

        }
        //��ѡ������
        t.zu=next;
        t.f=s.f;
        t.v=s.v;
        q.push(t);

    }
}

int main()
{

    int N,m;
    cin>>N>>m;
    int a,b,c;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        allGoods[i].v=a*b;
        allGoods[i].f=a;
        if(c==0)
        {
            Zu[i]=i;
            maxZu=max(maxZu,i);
        }
        else
        {
            allGoods[i].pre=Zu[c];
            Zu[c]=i;
            maxZu=max(maxZu,c);
        }

    }
    State s;
    s.f=N;
    s.v=0;
    s.zu=1;
    q.push(s);
    Func();


    printf("%d",maxx);
}
