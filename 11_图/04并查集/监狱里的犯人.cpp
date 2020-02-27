#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
	int value;
};
//����Ҫ�ú����ľ���������ݽṹ��ǰ��m�������������ϡ��ص��Ǻ���m����ʾ���ǵ��˵����������ǵ��˵�ֵ��
//��������f[1+m]=2����ʾ����1�ŵĵ�����2�ţ�����2�������ĸ���Ӫ���ǿ�find������ʵ�ֵġ���2�ŵ�bossҲ���޹�ϵ�� 
int f[100];
node nodes[100];
bool sortFunc(node a,node b)
{
	if(a.value>b.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//��ͣ������֧��boss��ͬʱ����f[x]��ֵ 
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
//�������ӣ����ַ�ʽ����������������ġ��޷�ȷ��˭��˭�����棬boss��˭��������Ҫ��ֻҪ��֤��һ������ 
void join(int x,int y)                     
{

    int fx=find(x), fy=find(f[y]);             
    if(fx != fy) 
	{//�������� 
		f[fx]=fy;
	}                           
         
		                      
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		f[i]=i;
	}
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&nodes[i].x,&nodes[i].y,&nodes[i].value);
	}
	sort(nodes,nodes+n,sortFunc);
	int idx=0;
	int a,b;
	while(1)
	{
		a=find(nodes[idx].x);	//�ҵ�һ����boss 
		b=find(nodes[idx].y);	//�ҵڶ�����boss 
		if(a==b)//�޷�����ˣ��˳� 
		{
			break;
		}
		if(f[nodes[idx].x+m]==0)
		{
			f[nodes[idx].x+m]=nodes[idx].y;
		}
		else
		{
				//ʹ��boss���µ�ǰ��������ڹ鲢���� 
			join(nodes[idx].y,f[nodes[idx].x+m]);
		}
		if(f[nodes[idx].y+m]==0)
		{
			f[nodes[idx].y+m]=nodes[idx].x;
		}
		else
		{
			join(nodes[idx].x,f[nodes[idx].y+m]); 
		}		
		
		idx++;
		
	} 
	printf("%d",nodes[idx].value);
	 
}

