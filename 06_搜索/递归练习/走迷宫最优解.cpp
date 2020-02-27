#include<cstdio>
#include<queue>
using namespace std;

const int M=10;
const int N=10;

char a[M][N+1]={
"#S######.#",
"......#..#",
".####.##.#",
".....#....",
"##.##.####",
"....#....#",
".#######.#",
"....#.....",
".####.###.",
"........G#"
};
int b[M][N+1];
int steps=1;
struct point{
	int x,y;
};
point start,end;
queue<point>  queList;
int stepx[4]={-1,0,1,0};//иосробвС 
int stepy[4]={0,1,0,-1};
point buffer[M*N];
int bufferIndex;
point temp;
void find_way()
{
	if(queList.size()==0) return;
	point p;
	int x,y;
	bufferIndex=0;
	while(queList.size())
	{
		p=queList.front();
		queList.pop();
		x=p.x;y=p.y;
		b[x][y]=steps;
		if(x==end.x&&y==end.y)
		{
			return;
		}
		int nx,ny;
		for(int i=0;i<4;i++)
		{
			nx=x+stepx[i];ny=y+stepy[i];
			if(nx>=0&&nx<M&&ny>=0&&ny<N)
			{
				if(a[nx][ny]!='#'&&b[nx][ny]==0)
				{
				
					temp.x=nx;temp.y=ny;
					buffer[bufferIndex++]=temp;
				}
			}
		}
		
	}
	steps++;
	for(int i=0;i<bufferIndex;i++)
	{
		queList.push(buffer[i]);
	}
	find_way();
}


int main()
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(a[i][j]=='S')
			{
				start.x=i;start.y=j;
			}
			if(a[i][j]=='G')
			{
				end.x=i;end.y=j;
			}
		}
	}	
	queList.push(start);
	find_way();
	printf("%d",b[end.x][end.y]);
}
