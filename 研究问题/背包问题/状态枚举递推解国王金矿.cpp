#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
struct goods{
int v;
int f;
};
goods G[100]={{200,3},{300,4},{350,3},{400,5},{500,5}};
//对该题，状态可以由level+left来定义
struct State{
int level;//处于哪个阶段
int left;//剩余多少人
int value;//当前状态的最优解
//保存状态之间的迁移--未使用
int preStateLevel;
int preStateLeft;
};
/*这种方法
1.优势：只计算了所有的可能状态，没有对人数从0-10进行枚举，减少了无效状态
2.同样带有剪枝功能
3.适用于状态之间的递推（选择） 不是简单的数学表达式的计算。
4.劣势在于，如果有大量的重叠子问题，会重复生成State节点。且无法查表直接得到每个子问题的解。
5.另外劣势在于，如果一个状态由前面多个状态的解得到，因为无法查找得到子问题的解，所以无法适用
改进：
1.保存每个状态的解，便于后续访问
2.同一个状态的解保留最优的那个
3.这里因为我们没有对所有无效状态枚举，我们应该只保留有效状态，不适合用二维数组，使用map实现。
*/
typedef map<int,int> sec;
map<int,sec> allState;
queue<State> q;

int func()
{
    int maxx=0;
    State s;
    State t;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        if(s.level>=5)
        {
            if(s.value>maxx)
            {
                maxx=s.value;
            }
        }
        else
        {
            //当前状态，两种选择
            //1.能选
            if(s.left>=G[s.level].f)
            {
                t.preStateLevel=s.level;
                t.preStateLeft=s.left;

                t.level=s.level+1;
                t.left=s.left-G[s.level].f;
                t.value=s.value+G[s.level].v;
                q.push(t);
                allState[t.level][t.left]=max(allState[t.level][t.left],t.value);//保存状态的解
            }
            //2.不能选
            t.preStateLevel=s.level;
            t.preStateLeft=s.left;

            t.level=s.level+1;
            t.left=s.left;
            t.value=s.value;
            q.push(t);
            allState[t.level][t.left]=max(allState[t.level][t.left],t.value);
        }
    }
    return maxx;
}
int main()
{
    State t;
    t.level=0;
    t.left=10;
    t.value=0;
    q.push(t);
    int c=func();
    printf("%d\n",c);
    //输出所有状态的解
    for(map<int,sec>::iterator i=allState.begin();i!=allState.end();i++)
    {
        sec eachLevel=(*i).second;
        for(sec::iterator j=eachLevel.begin();j!=eachLevel.end();j++)
        {
            printf("level=%d,left=%d,value=%d\n",(*i).first,(*j).first,(*j).second);

        }

    }

}
