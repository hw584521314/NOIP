#include<stdio.h>
#include<string.h>
char a[200]={0};
char b[200]={0};
char d[200]={0};
int main()
{
	char c[200];
	//��������������� 
	scanf("%s",c);
	int l=strlen(c);
	int idx=0;
	for(int i=l-1;i>=0;i--)
	{
		a[idx]=c[i]-'0';
		idx++;
	}
	scanf("%s",c);
	l=strlen(c);
	idx=0;
	for(int i=l-1;i>=0;i--)
	{
		b[idx]=c[i]-'0';
		idx++;
	}
	//��ʼ���г˷�����
	int jw=0;
	int temp;
	for(int i=0;i<200;i++)
	{//i������������� 
		jw=0;//��λ���� 
		for(int j=0;j<200;j++)
		{//j�������������� 
			temp=b[i]*a[j]+jw;//�ó���b[i]����ȥ���Ա�����a[j] 
			temp=temp+d[i+j];//����ԭ���Ľ�����ֵ��������b[i]�����������d[i] 
			d[i+j]=temp%10;
			jw=temp/10; 
		}
	}
	//��ʼ�������
	//��ȡʲôʱ��ÿ�ʼ��� 
	idx=200-1;
	for(;idx>=0;idx--)
	{
		if(d[idx]!=0)
		{
			break;
		}
	}
	//idx����Ҫ���ֵ����ʼȫ����� 
	
	for(int i=idx;i>=0;i--)
	{
		printf("%d",d[i]);
	}
}
