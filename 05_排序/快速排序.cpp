#include <bits/stdc++.h>

using namespace std;
int a[10]={5,8,1,4,9,7,3,6,0,2};

void quickSort(int left,int right)
{
    if(left>=right)
    {//�ݹ����������������������ڵ����ұ�����
        return;
    }
    int baseValue=a[left];//��׼ֵ

    int leftIndex=left;//�������
    int rightIndex=right;//�ұ�����
    int direct=1;//��ʾ����
    while(leftIndex<rightIndex)
    {
        if(direct==1)
        {
             if(a[rightIndex]<baseValue)
            {
                a[leftIndex]=a[rightIndex];
                leftIndex++;
                direct=0;
            }
            else
            {
                rightIndex--;
            }
        }
        else
        {
            if(a[leftIndex]>baseValue)
            {
                a[rightIndex]=a[leftIndex];
                rightIndex--;
                direct=1;
            }
            else
            {
                leftIndex++;
            }
        }

    }
    a[leftIndex]=baseValue;
    quickSort(left,leftIndex-1);
    quickSort(leftIndex+1,right);

}
int main()
{
   quickSort(0,9);
    return 0;
}
