#include<stdio.h>
#include<string.h>
int a[100]={0};
int b[100]={0};
int c[10000]={0};
char buffer[100];
int main()
{
	//��������a 
	scanf("%s",buffer);
	int l1=strlen(buffer);
	int index=0;
	for(int i=l1-1;i>=0;i--)
	{
		a[index++]=buffer[i]-'0';
	}
	//����b 
	scanf("%s",buffer);
	int l2=strlen(buffer);
	index=0;
	for(int i=l2-1;i>=0;i--)
	{
		b[index++]=buffer[i]-'0';
	}
	//����
	int temp,i,j;
	for(i=0;i<l2;i++)
	{
		//i����b��ÿһ������j����a��ÿһ���� 
		int p=0;//��λ
		for(j=0;j<l1;j++)
		{
			temp=b[i]*a[j]+c[i+j]+p;
			c[i+j]=temp%10;
			p=temp/10;
		}	
		//�˷���λ�������
		int tempi=i+j;
		while(p!=0)
		{
			c[tempi++]=p%10;
			p=p/10;
		}		 
	} 
	index=10000-1;
	while(c[index]==0){
		index--;
	}
	for(int i=index;i>=0;i--)
	{
		printf("%d",c[i]);
	}
	return 0;	
} 
