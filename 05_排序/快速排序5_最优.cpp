#include<stdio.h>
#include<iostream>
using namespace std;
int A[1000001]={6,2,4,3,6,9,8,7,1,5};
//{1,2,3,4,5,6,7,8,9,10};
//{6,2,4,3,6,9,8,7,1,5};
int N;
//�������������ĸ��Ż���ʽ��ʹ���м������Ϊ��λ�� 
void quickSort(int l,int r)
{
	if(l>=r) return;
	int m=A[(l+r)/2];	
	int lt=l,rt=r;
	while(lt<=rt)
	{
		//����û��==���ţ���Ϊ��ʹ��������������m��ͣ�����������ں������ƶ��У�m��ֵ������һ���ƶ�
		//������ϸ˼�����ᷢ��һ����������߻����ұ�һ��ָ����mֵ����m�ͻ���������ÿһ�ν����������� 
		//��ÿһ�ν�����ͨ��swap���lt++��rt--,�ֲ���ָ��mֵ���������Ϊ���յ�lt��rt��������m���� 
		//ȷ���ˣ�ȷʵ��������������ε�һ����Ϻ�,m=6,Ϊ:5 2 4 3 1 9 8 7 6 6. lt=5, rt=4
		//�����ܺ��磬ʵ����lt��rt���������ݷֳ���С��6�ʹ���6. 
		while(A[rt]>m) rt--;
		while(A[lt]<m) lt++;
		
		if(lt<=rt)
		{
			//==Ҳִ��һ����Ҫ��Ϊ��ִ�������lt++��rt-- 
			swap(A[lt],A[rt]);	
			lt++;
			rt--;
		}				
	}
	quickSort(l,rt);
	quickSort(lt,r);
}

int main()
{
	N=10;
	/*scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	*/
	quickSort(0,N-1);
	for(int i=0;i<N;i++)
	{
		printf("%d ",A[i]);
	}
}
