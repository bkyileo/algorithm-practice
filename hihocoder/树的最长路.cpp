// 树的最长路

#include<bits/stdc++.h>
using namespace std;
vector<int> edge[100005];
int vis[100005];
int	node;
int dep;
void dfs(int currdep,int curr)
{
	if(currdep>dep)
	{
		dep=currdep;
		node=curr;
	}
	vis[curr]=true;
	for(int i=0;i<edge[curr].size();++i)
	{
		if(vis[edge[curr][i]]) continue;
		dfs(currdep+1,edge[curr][i]);
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;++i)
	{
		int b,e;
		cin>>b>>e;
		edge[e].push_back(b);
		edge[b].push_back(e);
	}
	dep=0;
	memset(vis,0,sizeof(vis));
	dfs(0,1);
	memset(vis,0,sizeof(vis));
	dep=0;
	dfs(0,node);
	cout<<dep<<endl;
	return 0;
} 
