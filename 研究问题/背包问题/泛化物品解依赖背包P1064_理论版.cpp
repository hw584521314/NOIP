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

int dp[32001];
int ZuDp[61][32001];
int fanHuaInitial(int a,int b)
{
    for(int i=0;i<=b;i++)
    {
        if(i>=allGoods[a].f)
        {
            ZuDp[a][i]=allGoods[a].v;
        }
    }
    for(int k=Zu[a];k!=a;k=allGoods[k].pre)
    {
        for(int t=b-allGoods[a].f;t>=allGoods[k].f;t--)
        {
            ZuDp[a][allGoods[a].f+t]=max(ZuDp[a][allGoods[a].f+t],ZuDp[a][allGoods[a].f+t-allGoods[k].f]+allGoods[k].v);
        }
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
    //组间进行01背包
    for(int i=1;i<=maxZu;i++)
    {
        if(Zu[i]==0) continue;
        fanHuaInitial(i,N);
    }
    for(int i=1;i<=maxZu;i++)
    {
        if(Zu[i]==0) continue;
        for(int j=N;j>=0;j--)
        {
            for(int k=0;k<=j;k++)
            {
                dp[j]=max(dp[j],dp[k]+ZuDp[i][j-k]);
            }
        }
        for(int j=0;j<=N;j+=100)
        {
            printf("%d,",dp[j]);
        }
        printf("\n");
    }


    printf("%d",dp[N]);
}
