#include<stdio.h>


int a[9][9]=
{
	{9,0,0, 2,0,0, 0,0,0},
	{8,0,0, 3,0,0, 0,0,4},
	{0,3,5, 9,0,6, 0,0,0},
	
	{0,0,0, 0,0,0, 8,7,0},
	{0,6,0, 0,0,0, 0,3,0},
	{0,5,7, 0,0,0, 0,0,0},
	
	{0,0,0, 8,0,3, 6,4,0},
	{3,0,0, 0,0,2, 0,0,5},
	{0,0,0, 0,0,1, 0,0,2}
};
struct se{
	int start,end;
};
int amid[9][9]={
0,0,0,1,1,1,2,2,2,
0,0,0,1,1,1,2,2,2,
0,0,0,1,1,1,2,2,2,

3,3,3,4,4,4,5,5,5,
3,3,3,4,4,4,5,5,5,
3,3,3,4,4,4,5,5,5,

6,6,6,7,7,7,8,8,8,
6,6,6,7,7,7,8,8,8,
6,6,6,7,7,7,8,8,8,
}; 
unsigned int row[9]={0};//�б��  ���顣ÿһ������ĳһ�� ��1~9�Ƿ��Ѿ����ˣ�������Ӧ��λ��1������Ϊ0 
unsigned int col[9]={0}; 
unsigned int mid[9]={0};//С���� ���飬ÿһ������3*3������1~9�Ƿ��Ѿ����ˡ� 
bool v(int i,int j,int value)
{
	//�ж����Ƿ���� 
	if(((1<<value)&row[i])!=0) return false;
	//�ж����Ƿ���� 
	if(((1<<value)&col[j])!=0) return false;
	//�ж�����С9���Ƿ���� 
	if(((1<<value)&mid[amid[i][j]])!=0) return false;
	
	return true; 
}
//����value��Ӧ�ı�־λΪ1 
void fillValue(int i,int j,int value)
{
	 row[i]=row[i]|(1<<value);
	 col[j]=col[j]|(1<<value);
	 mid[amid[i][j]]=mid[amid[i][j]]|(1<<value);
}
//���value��Ӧ�ı�־λ����0. 
void clearValue(int i,int j,int value)
{
	row[i]=row[i]&~(1<<value);
	 col[j]=col[j]&~(1<<value);
	 mid[amid[i][j]]=mid[amid[i][j]]&~(1<<value);
}
//�Ѷ�ά����תΪ1ά���� 
bool fill(int idx)
{
	int j=idx%9;//�õ��� 
	int i=idx/9;//�� 
	//��д��ϣ� �����е����˵��ǰ�涼Ϊtrue����ΪֻҪ��false��Ҫ�ع��� 
	if(idx==81)
	{
		//��ӡ�������
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		 } 
		return true; 
	}
	//��ʼ�������
	//�����ǰλ���Ѿ���ֵ��ֱ����һ���ж� 
	if(a[i][j]!=0)
	{
		return fill(idx+1);
	} 
	//���û��ֵ������ֵ
	int flag=0; 
	//��־λ�������λ��1~9һ������������򷵻�false�����򣬷���true��
	//Ҫ��1~9��ÿһ���������б�����ֻҪ����ͼ�����ǰ������ 
	for(int n=1;n<=9;n++)
	{
		if(v(i,j,n)==true)		
		{
			a[i][j]=n;	
			fillValue(i,j,n);	
			fill(idx+1);//����������ͼ�����ǰ��������ʱ����ֵ����Ҫ�� 
			a[i][j]=0;//��������
			clearValue(i,j,n); 
			flag=1;
		}
	}
	if(flag==1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

int main()
{
	//��ʼ���������
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			fillValue(i,j,a[i][j]); 
		}
	 } 
	fill(0);
}

