#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
#include<memory.h>
using namespace std;
struct goods{
int f;
int v;
};
goods allGoods[61][100];
int idx[61];
int maxZu;
int dp[40000];
int hp[40000];
int main()
{

    int N,m;
    cin>>N>>m;
    int a,b,c;
    for(int i=1;i<=m;i++)
    {

        cin>>a>>b>>c;
        if(c==0)
        {
            allGoods[i][idx[i]].f=a;
            allGoods[i][idx[i]].v=b*a;
            idx[i]++;
            maxZu=max(maxZu,i);
        }
        else
        {
            allGoods[c][idx[c]].f=a;
            allGoods[c][idx[c]].v=b*a;
            idx[c]++;
            maxZu=max(maxZu,c);
        }
    }
    for(int i=1;i<=maxZu;i++)
    {
        if(allGoods[i][0].f!=0)
        {
            //���ÿ���飬�������ķ�����Ʒ��������dp��
            memset(dp,0,sizeof(dp));
            for(int j=N;j>=0;j--)
            {
                for(int k=allGoods[i][0].f;k<=j;k++)
                {
                    dp[k]=allGoods[i][0].v;
                }
                for(int k=1;k<idx[i];k++)
                {
                    for(int t=j-allGoods[i][0].f;t>=allGoods[i][k].f;t--)
                    {
                        dp[allGoods[i][0].f+t]=max(dp[allGoods[i][0].f+t],dp[allGoods[i][0].f+t-allGoods[i][k].f]+allGoods[i][k].v);
                    }
                }
            }
            //��������Ӧ�ķ�����Ʒ��֮ǰ������
            for(int j=N;j>=0;j--)
            {
                for(int k=0;k<=j;k++)
                {
                    hp[j]=max(hp[j],hp[j-k]+dp[k]);
                }
            }
        }
    }
    printf("%d",hp[N]);
}
