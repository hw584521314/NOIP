/*����n�� 1~10�໥��ϵ-���ѣ�
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
	scanf("%d",&n);
	int x,y;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		join(x,y);
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



