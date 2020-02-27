#include<stdio.h>
int a[10]={1,2,3,4,5,4,7,8,9,0};//{6,2,4,3,6,9,8,7,1,5};
void swap(int &a,int &b)
{
	int c;
	c=a;a=b;b=c;
}
void qsort(int left,int right)
{
	if(left>=right) return;
	int tl=left,tr=right;
	int f=a[tl];
	bool isLeft=true;//�������ٵ�ǰ�������׼ֵ����໹�����Ҳ࣬�����������λ 
	//a[tl]��a[tr]��һ����һ��һֱ�����ű������ʵ�Ǳ���ںͲ�ͬ����֮������ƶ���
	
	while(tl<tr)
	{
		while(a[tl]<f) tl++;
		while(a[tr]>f) tr--;
		//�ƶ������յĽ�����϶���tl==tr��Ҳ���ǻ��غ� 
		//�������������жϣ�������һ����tl==trʱ��ѭ���������� 
		if(tl>=tr) break; 
		swap(a[tl],a[tr]);
		if(isLeft)
		{//�������࣬�򽻻���䵽�Ҳ࣬����Ӧ������������Ҳ಻�� 
			tl++;
		}
		else
		{
			tr--;
		}
		isLeft=!isLeft;
	}
	if(tl>tr)
	{
		printf("impossible by analyze\n"); 
	 } 
	//ѭ�����ʱֻ��һ�������tl==tr
	//���Ԫ�ؾͿ�����tlλ�� 
	qsort(left,tl-1);
	qsort(tl+1,right);	
} 

int main()
{
	qsort(0,9);
	for(int i=0;i<10;i++)
	{
		printf("%d,",a[i]);
	}
}
