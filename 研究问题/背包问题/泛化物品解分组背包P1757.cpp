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
//ÿһ�鿴��������Ʒ
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
    //dp[j]��ʵ����һ��������Ʒ��dp[j]һֱ�����ã���õķ�����Ʒ�ͺ���һ��ʵ����Ʒ������͡�
    for(int i=1;i<=maxZu;i++)
    {
        for(int j=m;j>=0;j--)
        {
            //�����ڵ�ÿһ���������жϣ�ͬһ�����£����������Ǹ�
            //��������ڶԷ�����Ʒ��ʵ����Ʒ��͵Ĺ��̣�����ֱ��ʹ�����ڵ�Ԫ�أ���k=0~jЧ�ʸ���
            for(int k=Zu[i];k!=0;k=allGoods[k].pre)
            {
                if(j>=allGoods[k].f)
                //��һ����ʵʵ���˰ѷ���j�����Ϊ��j-allGoods[k].f��allGoods[k].f�����֣��ټ���dp[j]����ʵʵ����j��ȫ��ϸ�֣��ұ�k=0~jЧ�ʸ���
                dp[j]=max(dp[j],dp[j-allGoods[k].f]+allGoods[k].v);
            }
        }
    }
    printf("%d",dp[m]);
}
