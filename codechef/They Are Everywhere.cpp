//codeforces They Are Everywhere
#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
bool check()
{
	for(auto i:mp)
		if(i.second==0)return false;
	return true;
}
int main()
{
	int n;
	cin>>n;
	string flats;
	cin>>flats;	
	for(int i=0;i<n;++i)
	{
		  if (mp.find(flats[i])==mp.end())mp[flats[i]]=0;
	}
	int fast=0,slow=0;
	int res=INT_MAX;
	while(fast<n)
	{
		mp[flats[fast++]]++;
		//for(auto i:mp)cout<<i.first<<" "<<i.second<<endl;cout<<endl;
		while(mp[flats[slow]]>1){mp[flats[slow++]]--;}
		//for(auto i:mp)cout<<i.first<<" "<<i.second<<endl;cout<<endl;
		//cout<<fast<<" "<<slow<<endl;
		if(check())res=min(res,fast-slow);
	}
	cout<<res<<endl;
	return 0;
}
