// hihocoder Ê÷½á¹¹ÅÐ¶¨
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m;cin>>n>>m;
		set<int> es[505];
		for(int i=0;i<m;++i)
		{
			int a,b;cin>>a>>b;
			es[a].insert(b);
			es[b].insert(a);
		}
		if(n!=m+1) 
		{
			cout<<"NO"<<endl;
			continue;
		}
		queue<int> q;
		for(int i=0;i<505;++i)
		{
			if(es[i].size()==1)q.push(i);
		}
		vector<int> temp;
		while(!q.empty())
		{
			int curr=q.front();
			q.pop();
			temp.push_back(curr);
			es[*es[curr].begin()].erase(curr);
			if(es[*es[curr].begin()].size()==1)
			{
				q.push(*es[curr].begin());
			}
		}
		if(temp.size()==n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
}
