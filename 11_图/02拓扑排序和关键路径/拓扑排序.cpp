//����������Ҫ��������޻�ͼ��������ϵ���
//�����������󣬺���ڵ�һ��������ͼ�ĺ�̽ڵ㣬��������ǰ���ڵ�
//���������ɹ������ŵȵȡ� 
//���ȼ���ÿ���ڵ�����

#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;

main()
{
	queue<int> q;//���У����ڹ������������ÿ�ΰ����Ϊ0��ѹ�� 
	int in[100]={0};//����ÿ���ڵ������Ƕ��� 
	vector<int> edge[100];//����ÿ���ڵ�ıߵĹ�ϵ 
	int n;//n���ڵ� 
	int m;//m������ 
	scanf("%d%d",&n,&m);
	//��ȡ����ͼ 
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
	} 
	//����ÿ���ڵ����� ������ĿҪ��û��0����1��ʼ 
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<edge[i].size();j++)
		{
			in[edge[i][j]]++;
		}
	} 
	//�����Ϊ0��ѹ�� 
	for(int i=1;i<=n;i++)  //n  �ڵ������
	{
		if(in[i]==0) q.push(i);  //�����Ϊ0�ĵ������
	}
	 
	vector<int>ans;   //ans Ϊ��������
	while(!q.empty())
	{
		int p=q.front(); q.pop(); // ѡһ�����Ϊ0�ĵ㣬������
		ans.push_back(p);//�ѽ��ѹ��vector 
		for(int i=0;i<edge[p].size();i++) 
		{//����㼴��ɾ����ɾ��ǰ���Ƚ�ÿ���ӽڵ����ȼ��� 
			int y=edge[p][i];
			in[y]--;
			if(in[y]==0)//���Ϊ0����ѹ����� 
				q.push(y);  
		}
	}
	if(ans.size()==n)   
	{
		for(int i=0;i<ans.size();i++)
			printf( "%d ",ans[i] );
		printf("\n");
	}
	else printf("No Answer!\n");   //  ans �еĳ�����n����ȣ���˵������������
	
}




