//���ֺͣ����ٵ������ɽ�
/*˼·����ʵ�����ĩβ��ʼ��ǰ�ݹ�Ļ�������ֻ��Ҫ��֤�����С��������
Ȼ��ʹ��DFS�������һ��⼴�� 
*/ 
#include<bits\stdc++.h>
using namespace std;
int a[6]={5,4,2,9,11,8};
int b[6]={0}; 

int f(int s,int x,int l)
{
	if(s<0) 
	{
		return 0;
	}
	else if(s==0)
	{	
		for(int i=0;i<l;i++)
		{
			printf("%d,",b[i]);
		}
		printf("\n");	
		return 1;
	}
	else if(x<0)
	{//���������ں��棬��Ϊ�п���x<0ʱ��s�պõ���0 
		return 0;
	}

	//��ѡ��
	b[l]=a[x];
	if(f(s-a[x],x-1,l+1)==1)
	{
		return 1;
	}
	b[l]=0;
	//��ѡ�� 
	return f(s,x-1,l);

}

int main()
{
	//����
	sort(a,a+6); 
	int b=20;
	f(b,5,0);
			
}  
