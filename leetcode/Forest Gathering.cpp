#include<bits/stdc++.h>
using namespace std;
/*
�������ݵĵ�һ�а����������� N��W �� L���ֱ�������Ŀ���������Ҫ������ߣ��Լ���
���ܿ����������ߡ�
������ N �У�ÿ������һ������������������ Hi �� Ri��
1 �� N �� 105
1 �� W, L �� 1018
1 �� Hi, Ri �� 109
*/
struct tree
{
	long long h;
	long long r;
	tree(long long x,long long y):h(x),r(y){
	}	
};
bool can(long long w,long long l,vector<tree> trees,long long month)
{
	long long temp=0;
	long long height=0;
	for(auto i:trees)
	{
		height = (i.h + month * i.r);
		if(height>=l)
		{
			temp+=height;
		}
		if(temp>1000000000000000001LL)
		break;
	}
	if(temp>=w)
		return true;
	else
		return false;
}
int main()
{	
	int N;
	long long M,L;
	cin>>N>>M>>L;
	vector<tree> trees;
	int H,R;
	while(N--)
	{
		cin>>H>>R; 
		trees.push_back(tree(H,R));
	}
	long long l;
	long long r=1;
	while(!can(M,L,trees,r))
	{
		r=r<<1;
	}
	l=r>>1;
	long long mid;
	while(l!=r-1)
	{
		mid=(l+r)>>1;
		if(can(M,L,trees,mid))
			r=mid;
		else
			l=mid;
	}
	if(can(M,L,trees,l))
		cout<<l<<endl;
	else
		cout<<r<<endl;
} 
