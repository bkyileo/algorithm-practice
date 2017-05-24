// code chef Book Game with Chef
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[22][2][2];
int nums[22];
int make(ll n)
{
	int index=0;
	while(n)
	{
		nums[index++]=n%10;
		n/=10;
	}
	index--;
	return index;
}
ll dfs(int curr,bool istrue,bool high,int condi,bool sta)
{
	if(curr==-1&&istrue)return 1;
	if(curr==-1&&!istrue)return 0;
	if(!high&&dp[curr][istrue][sta]!=-1)return dp[curr][istrue][sta];
	ll res=0;
	int e = high?nums[curr]:9;
	for(int i=0;i<=e;++i)
	{
		bool flag=istrue;
		if(i==0&&sta) flag=istrue|(i==condi);
		if(i)flag=istrue|(i==condi);
		res+=dfs(curr-1,flag,high&&(i==e),condi,sta||i);
	}
	if(!high)
		dp[curr][istrue][sta]=res; 
	return res;
}
ll gcd(ll a,ll b)
{
	assert(a>=b);
	return a%b==0?b:gcd(b,a%b);
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		ll n;cin>>n;
		ll res=0;
		memset(nums,0,sizeof(nums));
		int index=make(n);
		//for(int i=0;i<=index;++i)cout<<nums[i]<<" ";cout<<endl;
		memset(dp,-1,sizeof(dp));
		//cout<<dfs(index,0,1,0,0)<<endl;
		for(int i=0;i<=9;++i)
		{
			memset(dp,-1,sizeof(dp));
			res+=dfs(index,0,1,i,0);
		}
		ll gd=gcd(10*n,res);
		cout<<res/gd<<"/"<<10*n/gd<<endl;
		
	}
	return 0;
}
