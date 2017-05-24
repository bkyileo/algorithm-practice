//离散化 STL 工具测试代码
#include<bits/stdc++.h>
using namespace std;
/*
使用STL算法离散化： 
思路：先排序，再删除重复元素，然后就是索引元素离散化后对应的值。 
假定待离散化的序列为a[n]，b[n]是序列a[n]的一个副本，则对应以上三步为：
*/
int main()
{
	/*
	经离散化后对应的值
	对于第3步，若离散化后序列为0, 1, 2, ..., size - 1则用lower_bound，
	从1, 2, 3, ..., size则用upper_bound，其中lower_bound返回第1个不小于b[i]的值的指针，
	而upper_bound返回第1个大于b[i]的值的指针，
	当然在这个题中也可以用lower_bound然后再加1得到与upper_bound相同结果，
	两者都是针对以排好序列。使用STL离散化大大减少了代码量且结构相当清晰。
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
	int size=unique(a,a+n)-a;//size为离散化后元素个数
	for(int i=0;i<n;i++)
		b[i]=lower_bound(a,a+size,b[i])-a + 1;
		
	cout<<"size : "<<size<<endl;

	for(auto i:b)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	
} 
