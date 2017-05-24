//stable number ms
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,curr;cin>>n;
	vector< set<int> > g(n+1);
	vector< set<int> > p(n+1);
	vector<int> deg(n+1,0);
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=0;j<k;++j)
		{
			cin>>curr;
			deg[i]++;
			g[curr].insert(i);
		}
	}
	queue<int> q;
	for(int i=0;i<=n;++i)
	{
		if(deg[i]==0)q.push(i);
	}
	int res=0;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		if(curr==0 || p[curr].size()>1 || p[curr].find(0)!=p[curr].end())
		{
			if(curr != 0) {
				res++;
			}
			for(auto i:g[curr])
			{
				p[i].insert(curr);
				deg[i]--;
				if(deg[i]==0)q.push(i);
			}			
		}
		else if(p[curr].size()==1)
		{
			for(auto i:g[curr])
			{
				p[i].insert(*p[curr].begin());
				deg[i]--;
				if(deg[i]==0)q.push(i);
			}	
		}

	}
	cout<<res<<endl;
	return 0;
} 
