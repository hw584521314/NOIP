#include<stdio.h> 
#include<set>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int row=10,col=17;
int startX,startY,endX,endY;
struct po{
	int x,y;
	
	po(int a=0,int b=0)
	{
		x=a,y=b;
	}
	bool operator<(const po &b) const
	{
		if(x==b.x)
		{
			return y<b.y;
		} 
		return x<b.x;
	} 
};

struct point{
	int x,y;
	int g,h,f;
	bool operator<(const point &b) const
	{
		return f>b.f;
	} 
	point(int x=0,int y=0)
	{
		this->x=x;
		this->y=y;
		g=0;
		Update(); 
	}
	point(point &parent,int X,int Y)
	{
		x=X;
		y=Y;
		g=parent.g+1;
		Update();
	}
	void Update()
	{
		h=abs(x-endX)+abs(y-endY);
		f=g+h;
	}
};

set<po> checked;
map<po,po > pre;
priority_queue<point> que;
int delX[4]={-1,0,1,0};
int delY[4]={0,1,0,-1};

char mapp[100][100]={
"00000000000000000",
"000000*****000000",
"0000000000*000000",
"0010000000*000000",
"0000000000*000000",
"0000000000*000000",
"00000******000000",
"00000000000000020",
"00000000000000000",
"00000000000000000",
};

int main() 
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(mapp[i][j]=='1')
			{
				startX=i,startY=j;
			}
			if(mapp[i][j]=='2')
			{
				endX=i,endY=j;
			}
		}
	}
	
	point t(startX,startY);
	que.push(t);
	
	while(que.size())
	{
		t=que.top();
		checked.insert(po(t.x,t.y));
		que.pop();
		if(t.x==endX&&t.y==endY)
		{
			printf("%d\n",t.g);
			break;
		} 
		for(int i=0;i<4;i++)
		{
			int newX=t.x+delX[i];
			int newY=t.y+delY[i];
			if(newX>=0&&newX<row&&newY>=0&&newY<col)
			{
				if((mapp[newX][newY]=='0'||mapp[newX][newY]=='2')&&checked.count(po(newX,newY))==0)
				{
					point tt(t,newX,newY);
					pre[po(newX,newY)]=po(t.x,t.y);
					que.push(tt);
				}
			}
		}
	}
	for(po i=pre[po(endX,endY)];!(i.x==startX&&i.y==startY);i=pre[i])
	{
		printf("(%d,%d)<-",i.x,i.y);
	}
} 

