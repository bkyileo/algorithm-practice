#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,l,r;cin>>t;
	long long tp;
	while(t--)
	{
		cin>>n>>m;
		vector<int> arr(n);
		for(int i=0;i<n;++i)cin>>arr[i];
		map<int,long long> mp;
		for(int i=0;i<n;++i)
		{
			l=1;
			for(int j=i-1;j>-1;--j)
			{
				if(arr[i]>arr[j])l++;
				else break;
			}
			r=1;
			for(int j=i+1;j<n;j++)
			{
				if(arr[i]>=arr[j])r++;
				else break;
			}
			tp=0;
			for(int len=1;len<=l+r-1;++len)
			{
				tp+=min(min(len,l+r-len),min(l,r));
			}
			mp[arr[i]]+=tp;
		}
		//for(auto i:mp)cout<<i.first<<" "<<i.second<<endl;
		for(int i=0;i<m;++i)
		{
			cin>>tp;
			for(map<int,long long>::reverse_iterator i=mp.rbegin();i!=mp.rend();++i)
			{
				if(tp<=i->second)
				{
					cout<<i->first<<endl;
					break;
				}
				else
				{
					tp-=i->second;
				}
			}
		}
	}
	return 0;
} 
