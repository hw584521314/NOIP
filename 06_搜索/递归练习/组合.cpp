#include <iostream>
using namespace std;
//aΪ��Ŵ���ϵ���ֵ��bΪ�����ݴ������
//n��m�����n��ȡ��m��������� 
// M=m M������� 
int a[]={0,1,2,3,4};
int b[5];
void c(int n, int m,const int M)
{
	if(m==0)
	{
		for(int i =0 ; i<M;i++)
			printf("%d",b[i]);
		printf("\n");
		return;
	}	
	for (int i =n;i>=m;i--)
	{
		//ȷ���ҵĵ�m���ֵ 
		b[m-1]=a[i-1];	
		//����ȷ���˵�ǰλ�õ�ֵ
		//���´εݹ�c(n-1,m-1) 
		c(i-1,m-1,M);
	}	
}
 
int main ()
{
	c(5,3,3); 
	return 0;
} 

