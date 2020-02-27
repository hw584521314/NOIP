#include<stdio.h>
//������߶�����1��ʼ���������Һ��Ӳ���0��Ӱ�� 
//ԭʼ���� 
int value[10]={0,1,2,3,4,5,6,7,8,9};
//����� 
struct Point{
	int l,r;
	int sum;
	int tag;
};
//�����߶��� 
Point tree[10<<2];

//��ԭʼ���ݹ����߶���������߶����ĳ�ʼ��������ʹ�����ұհ�[left,right] 
void build(int i,int left,int right)
{
	tree[i].l=left;
	tree[i].r=right;
	if(left==right)
	{
		tree[i].sum=value[left];
		return;
	}
	int mid=(left+right)>>1;
	build(i<<1,left,mid);//���� ���й��� 
	build(i<<1|1,mid+1,right);//�Һ��ӽ��й��� 
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;//���Һ�����ɹ������ɸ��ڵ�ĸ�ֵ 
}
//�����:value�ĵ�dis��ֵ����Ϊv ��i�Ǳ��ڵݹ飬����ʱ�����Ǵ�i=1��ʼ 
void editPoint(int i,int dis,int v)
{
	//�ҵ������յ��Ǹ�Ҷ�ӽڵ㣬����� 
	if(tree[i].l==tree[i].r)
	{
		tree[i].sum=v;
		return;
	}
	//���disΪ ��߲��֣��������ߣ���������ұߡ����������Ǳհ�������ȡ���Ⱥ� 
	if(dis<=tree[i<<1].r) editPoint(i<<1,dis,v);
	else editPoint(i<<1|1,dis,v);
	//Ҷ�Ӹ�����ϵ�ͬʱ��ע������¸��ڵ㡣 
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
}
//�����ѯ��i����Ϊ�ݹ������������ʱ��ʼ��ʹ��i=0�����á�l���������±꣬r���������±ꡣ 
int query(int i,int l,int r)
{
	//����ڵ���ȫ���ڴ���������ڣ���ֱ�ӷ��ظýڵ��ֵ 
	if(tree[i].l>=l&&tree[i].r<=r) return tree[i].sum;	
	if(tree[i].r<l||tree[i].l>r) return 0;//����ڵ������û���κν��� 
	int sum=0;
	//�������䲿�ָ������䣬�������������ȡֵ�������ӵ����ӿ��ܾͺ�����û�н����ˣ����������ӵ��Һ��Ӻ������н��� 
	if(l<=tree[i<<1].r) 
		sum+=query(i<<1,l,r);
	if(r>=tree[i<<1|1].l)
		sum+=query(i<<1|1,l,r);
	return sum;
} 
//�����޸�:����Ϊ����ĳ��ֵv�����⻹��һ�־����������丳ֵΪ��һ��ֵ 
//Ҫʹ���Ż����ɣ�lazyTag������ʱ������������չ�����ǲ�ѯʱ����Ҫ���·�֧ʱ���Űѱ��������չ����֤����޶ȵ�������Ч 
void editSequence(int i,int l,int r,int v) 
{
	if(tree[i].l>=l&&tree[i].r<=r) 
	{
		tree[i].sum+=v*(tree[i].r-tree[i].l+1);//���������� 
		tree[i].tag+=v;//����ʹ��+=���ͱ�ʾ֧�ֶ�θ��£�һ�β�ѯ������ÿ�θ��µ�Ч�� 
		return;
	}
	if(tree[i].r<l||tree[i].l>r) return;
	if(l<=tree[i<<1].r) editSequence(i<<1,l,r,v);
	if(r>=tree[i<<1|1].l) editSequence(i<<1|1,l,r,v);
	//����ʵ�����ϱ���һ�£����ײ���ȫ��ͨ��tag����û����ȫ�������еĵײ���sum
	//�ں����ѯ���ײ���ʱ����ʵ�ֶ�Ӧ�ײ��ĸ��� 
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
	return;
}
int querySequence(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r) 
		return tree[i].sum;//�������ʱ�Ѿ���� 
	if(tree[i].r<l||tree[i].l>r) 
		return 0;
	//׼������lazyTag���̻���ǰ�����tag 
	if(tree[i].tag!=0)
	{
		tree[i<<1].tag+=tree[i].tag;//ע��+=��ʹ�� 
		tree[i<<1|1].tag+=tree[i].tag;
		//����ʱ��ͬʱ����sum��ֵ����Ϊû������������Ը���sum��ֵ������ʱ��������˵���ϰ벿���ǲ�ͬ�Ķ��ġ� 
		tree[i<<1].sum  += (tree[i<<1].r-tree[i<<1].l+1)*tree[i].tag;
		tree[i<<1|1].sum+= (tree[i<<1|1].r-tree[i<<1|1].l+1)*tree[i].tag;
		tree[i].tag=0;
	}
	
	//��ֵ 
	int sum=0;
	if(l<=tree[i<<1].r)
	{
		sum+=querySequence(i<<1,l,r);
	}
	if(r>=tree[i<<1|1].l)
	{
		sum+=querySequence(i<<1|1,l,r);
	}
	return sum;
}
void Debug()
{
	int i=1;
	int line=1;
	int lineNum=0;
	while(tree[i].l!=0)
	{
		printf("(l=%d,r=%d,t=%d,s=%d)  ",tree[i].l,tree[i].r,tree[i].tag,tree[i].sum);
		i++;
		lineNum++;
		if(lineNum==line)
		{
			printf("\n");
			line<<=1;
			lineNum=0;
		}
	}
}
int main()
{
	//���� 
	build(1,1,9);
	//�����ѯ 
	//printf("%d\n",query(1,3,5));
	//�����޸� 
	//editPoint(1,3,5);
	//�޸ĺ�������ѯ 
	//printf("%d\n",query(1,3,5));
	//�����޸�
	editSequence(1,1,6,1);
	editSequence(1,4,8,2);
	//Debug();
	//�����ѯ
	printf("%d\n",querySequence(1,3,6)); 
}
