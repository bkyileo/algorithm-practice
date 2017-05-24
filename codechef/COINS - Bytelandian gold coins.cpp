// spoj COINS - Bytelandian gold coins
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dfs(map<ll,ll> &mp,ll m)
{
	if (mp.find(m) != mp.end())
		return mp[m];
	else
	{
		mp[m]=max((dfs(mp,m/2)+dfs(mp,m/3)+dfs(mp,m/4)),m);
		return mp[m];
	}	 
}
int main()
{
	ll m;
	while(cin>>m)
	{
		map<ll,ll> mp;
		mp[0]=0;mp[1]=1;mp[2]=2;mp[3]=3;mp[4]=4;
		dfs(mp,m);
		cout<<mp[m]<<endl;
	}
	return 0;
} 
