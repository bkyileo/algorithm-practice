//hihocoder 刷油漆
#include<bits/stdc++.h>
using namespace std;
//N<=10^2，1<=Ai<=N, 1<=Bi<=N, 1<=Vi<=10^3, 1<=M<=N 
#define N 105 
vector<int> edge[N];

int dfs(int i,int m,vector<bool> &visit,vector< vector<int> > &dp)
{
	if(dp[i][m]!=0)
		return dp[i][m];
	visit[i]=true;
	for(int j=0;j<edge[i].size();++j)
	{
		if(visit[edge[i][j]]) continue;
		//dp[edge[i][j]][m-1]=
		dfs(edge[i][j],m-1,visit,dp);
		//0-1背包 
		for(int x = m; x >= 1; x--) 
		//完全背包 
		//for(int x = 1; x <= m; x++) 
			for(int y = 0; y <= m - x; y++) 
				dp[i][x+y] = max(dp[i][x+y],dp[i][x] + dp[edge[i][j]][y]);
	}
	//for(int j=0;j<edge[i].size();++j)
	//{
	//	dp[i][m]=max((dp[i][1]+dp[edge[i][j]][m-1]),dp[i][m]);
	//}
	return dp[i][m];
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector< vector<int> >dpr(n+1,vector<int>(m+1,0));
	vector<int> value(n);
	for(int i=1;i<=n;++i)
	{
		cin>>dpr[i][1];
	}

	for(int i=1;i<n;++i)
	{
		int e1,e2;
		cin>>e1>>e2;
		edge[e1].push_back(e2);
		edge[e2].push_back(e1);
	}
	
	int ans=0;

	vector< vector<int> >dp(dpr);
	vector<bool> visit(n,false);
	//cout<<dfs(i,m,visit,dp)<<endl;
	ans=dfs(1,m,visit,dp);

	cout<<ans<<endl;
	return 0;
} 
