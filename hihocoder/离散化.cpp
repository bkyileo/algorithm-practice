//��ɢ�� STL ���߲��Դ���
#include<bits/stdc++.h>
using namespace std;
/*
ʹ��STL�㷨��ɢ���� 
˼·����������ɾ���ظ�Ԫ�أ�Ȼ���������Ԫ����ɢ�����Ӧ��ֵ�� 
�ٶ�����ɢ��������Ϊa[n]��b[n]������a[n]��һ�����������Ӧ��������Ϊ��
*/
int main()
{
	/*
	����ɢ�����Ӧ��ֵ
	���ڵ�3��������ɢ��������Ϊ0, 1, 2, ..., size - 1����lower_bound��
	��1, 2, 3, ..., size����upper_bound������lower_bound���ص�1����С��b[i]��ֵ��ָ�룬
	��upper_bound���ص�1������b[i]��ֵ��ָ�룬
	��Ȼ���������Ҳ������lower_boundȻ���ټ�1�õ���upper_bound��ͬ�����
	���߶���������ź����С�ʹ��STL��ɢ���������˴������ҽṹ�൱������
	*/
	int a[10]={50,90,100,60,30,50,70,20,30,10};
	int b[10]={50,90,100,60,30,50,70,20,30,10};
	int n=10;
	for(auto i:a)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	sort(a,a+10);
	int size=unique(a,a+n)-a;//sizeΪ��ɢ����Ԫ�ظ���
	for(int i=0;i<n;i++)
		b[i]=lower_bound(a,a+size,b[i])-a + 1;
		
	cout<<"size : "<<size<<endl;

	for(auto i:b)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	
} 
