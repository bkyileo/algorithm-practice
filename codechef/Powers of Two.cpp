#include<bits/stdc++.h>
using namespace std;
vector<long long> hi;
int main()
{
	long long i=1;
	hi.push_back(i);
	while(i<INT_MAX)
	{
		hi.push_back(2*i);
		i=2*i;
	}
	long long res=0;
	map<long long,long long> mp;
	int nums;cin>>nums;
	while(nums--)
	{
		int curr;cin>>curr;
		for(auto i:hi)
		{
			res+=mp[i-curr];
		}
		mp[curr]++;
	}
	cout<<res<<endl;
	return 0;
}
