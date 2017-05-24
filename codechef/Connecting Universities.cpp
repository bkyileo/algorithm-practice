//codeforces Connecting Universities
#include<bits/stdc++.h>
using namespace std;
vector<int> edge[200005];
vector<bool> locate(200005,false);
int n,k,curr,c1,c2;
int root1,root2;
long long best=INT_MAX;
long long res;
int dfs1(int now,int pre)
{
	int cnt=0;
	if(locate[now])cnt++;
	for(auto i:edge[now])
		if(i!=pre)
			cnt+=dfs1(i,now);
	if(cnt>=k&&cnt<best)
	{
		root2=now;
		best=cnt;
	}
	return cnt;
}
void dfs2(int now,int pre,int d)
{
	if(locate[now])res+=1ll*d;
	for(auto i:edge[now])
		if(i!=pre)
			dfs2(i,now,d+1);
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<2*k;++i)
	{
		cin>>curr;
		locate[curr]=true;
	}
	for(int i=0;i<n-1;++i)
	{
		cin>>c1>>c2;
		edge[c1].push_back(c2);
		edge[c2].push_back(c1);
	}
	for(int i=1;i<=n;++i)
	{
		if(edge[i].size()==1)
		{
			root1=i;
			break;
		}
	}
	dfs1(root1,-1);
	res=0;
	dfs2(root2,-1,0);
	cout<<res<<endl;
	return 0;
}
