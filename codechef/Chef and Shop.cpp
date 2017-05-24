//Chef and Shop
#include<bits/stdc++.h>
using namespace std;
int cost[10];
int weight[10];
long long res;
void dfs(int i,int n,int k,long long curr)
{
	if(i==n){res=max(res,curr);return ;}
	else
	{
		res=max(res,curr);
		dfs(i+1,n,k,curr);
		if(k>=cost[i])
		{
			dfs(i+1,n,k-cost[i],curr+weight[i]);
		}
	}
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,k;cin>>n>>k;
		for(int i=0;i<n;++i)
		{cin>>cost[i]>>weight[i];}
		res=0;
		dfs(0,n,k,0);
		cout<<res<<endl;
	}
}
