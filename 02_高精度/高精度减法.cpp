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
	//�����ж�˭��˭С
	char *bjs;
	char *js;
	int flag=0;
	for(int i=200-1;i>=0;i--)
	{
		if(a[i]>b[i])
		{
			bjs=a;js=b;break;
		}
		else if(a[i]<b[i])
		{
			bjs=b;js=a;flag=1;break;
		}
	} 
	//��ʼ������
	int jw=0;//��λ��־
	int beijianshu;
	int temp;
	for(int i=0;i<200;i++)
	{
		beijianshu=bjs[i]-jw;//���ȼ���֮ǰ�Ľ�λ
		temp=beijianshu-js[i]; 
		if(temp>=0)
		{//����������λ 
			d[i]=temp;jw=0;
		} 
		 else
		{//�����������λ 
		 	d[i]=temp+10;jw=1;
		} 
	}
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
	if(flag==1)
	{
		printf("-");
	}
	for(int i=idx;i>=0;i--)
	{
		printf("%d",d[i]);
	}
}
