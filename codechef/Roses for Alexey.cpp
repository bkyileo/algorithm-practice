// Roses for Alexey
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,k,curr;cin>>t;
	int tp;
	while(t--)
	{
		cin>>n>>k;
		tp=0;
		map<int,int> mp;
		for(int i=0;i<n;++i)
		{
			cin>>curr;
			mp[curr]++;
			if(mp[curr]==k)
			{
				cp[curr]=0;
				tp++;
			}
		}
		
		
	}
	return 0;
}
