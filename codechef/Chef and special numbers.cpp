// code chef Chef and special numbers
#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
	对特殊数字的分析
	每增加一位都会对整除造成影响考虑高位增加一位对当前整除性质的影响
	dp关系
	0 no 严格问题
	1 ok 严格正确 
	2 ok 原来没问题 现在没问题
	3 ok 原来没问题 现在没问题 
	4 ok 原来没问题 现在没问题
	5 ok 原来没问题 现在没问题
	6 ok 原来没问题 现在没问题
	7 ok 原来没问题 现在没问题 
	8 ok 原来没问题 现在没问题
	9 ok 原来没问题 现在没问题
	dp数组设计 
	[18][10][10][1]
	LR 是第几个数字 
	index(r)-index(l)
*/ 

void slove()
{ 
	int t;cin>>t;
	ll l,r,k,count,curr;
	bool visit[10]; 
	while(t--)
	{
		cin>>l>>r>>k;
		ll res=0;
		for(ll i=l;i<=r;++i)
		{
			memset(visit,false,sizeof(visit));
			count=0;
			curr=i;
			while(curr)
			{
				int a=curr%10;
				if(a!=0&&i%a==0&&!visit[a])
				{
					count++;
					visit[a]=true;			
				}
				curr=curr/10;
			}
			if(count>=k)
				res++;
		}
		cout<<res<<endl;
	} 
	return ;
}
int main()
{
	slove();
	return 0;
} 
