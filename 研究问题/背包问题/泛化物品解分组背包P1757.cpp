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
int Zu[101];
int maxZu=0;
goods allGoods[1001];

int dp[1001];
//每一组看作泛化物品
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
    //dp[j]其实就是一个泛化物品，dp[j]一直被复用，求得的泛化物品和后面一个实际物品进行求和。
    for(int i=1;i<=maxZu;i++)
    {
        for(int j=m;j>=0;j--)
        {
            //对组内的每一个，进行判断，同一费用下，保留最贵的那个
            //这里就是在对泛化物品和实际物品求和的过程，而且直接使用组内的元素，比k=0~j效率更高
            for(int k=Zu[i];k!=0;k=allGoods[k].pre)
            {
                if(j>=allGoods[k].f)
                //这一步其实实现了把费用j，拆分为了j-allGoods[k].f和allGoods[k].f两部分，再加上dp[j]，其实实现了j的全部细分，且比k=0~j效率更高
                dp[j]=max(dp[j],dp[j-allGoods[k].f]+allGoods[k].v);
            }
        }
    }
    printf("%d",dp[m]);
}
