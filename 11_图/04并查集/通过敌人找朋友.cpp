/*����n�� 1~10�໥��ϵ-���ˣ�
�������һ����  a  b�� �ж� ab�Ƿ���һ���
һ������YES������NO 
*/
#include<stdio.h>

int a[100];
//����boss 
int find(int x)
{
	if(x==a[x]) return x;
	return a[x]=find(a[x]);//��ƽ�� 
}
//�����Ŷӵ�boss���кϲ� 
void join(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y) a[x]=y;
}

int main()
{
	int n;
	scanf("%d",&n);
	//��ʼ��
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	//�����ϵ����
	scanf("%d",&m);
	int x,y,t1,t2;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		t1=find(x) ;
		t2=find(y);
		if(a[t1+n]==0)
		{
			a[t1+n]=t2;
		}
		else
		{
			join(a[t1+n],t2);
		}
		if(a[t2+n]==0)
		{
			a[t2+n]=t1;
		}
		else
		{
			join(a[t2+n],t1);
		}
	} 
	//�ж��Ƿ���ͬһ��֯��
	scanf("%d%d",&x,&y);
	x=find(x);
	y=find(y);
	if(x==y)
	{
		return "YES";
	} 
	else
	{
		return "NO";
	}
 } 



