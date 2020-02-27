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
int Zu[100];
int maxZu=0;
goods allGoods[100];

int dp[100];
int f(int wupin,int fei)
{
    int maxx=0;
    for(int i=Zu[wupin];i!=0;i=allGoods[i].pre)
    {
        if(fei>=allGoods[i].f)
        {
            maxx=max(allGoods[i].v,maxx);
        }
    }
    return maxx;
}
int main()
{

    int n,m;
    cin>>m>>n;
    int a,b,c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        allGoods[i].f=a;
        allGoods[i].v=b;
        allGoods[i].pre=Zu[c];
        Zu[c]=i;
        maxZu=max(maxZu,c);
    }
    for(int i=1;i<=maxZu;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k=0;k<=j;k++)
            {
                int t=dp[k]+f(i,j-k);
                dp[j]=max(dp[j],t);
            }
        }
    }
    printf("%d",dp[m]);
}
