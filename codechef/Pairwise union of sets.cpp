#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--)
	{
		int n,k;cin>>n>>k;
		vector<vector<int>> mp(n);
		int res = 0;
		for(int i=0;i<n;++i)
		{
			int num,curr;cin>>num;
			for(int j=0;j<num;++j)
			{
				cin>>curr;
				mp[i].push_back(curr);
			}
		}
		int all = (k+1)*k/2;
		for(int i=0;i<n;++i)
		{
			int sum=0;
			vector<bool> visit(k+1,true);
			for(auto j:mp[i])
			{
				visit[j] = false;
				sum += j;
			} 
			for(int j=i+1;j<n;++j)
			{
				int sum2 = 0;
				for(int k=0;k<mp[j].size();++k)
				{
					if(visit[mp[j][k]]) sum2+=mp[j][k];
				}
				if((sum2+sum)==all)res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
} 
