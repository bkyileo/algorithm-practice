//Integer Break 

#include<bits/stdc++.h>
#define maxn 100
using namespace std;

int dp[100];
int dfs(int n)
{
	if(dp[n]!=-1) return dp[n];
	for(int i=2;i<n-1;++i)
		dp[n]=max(dfs(i)*dfs(n-i),dp[n]);
	return dp[n];
}
int integerBreak(int n) {
	memset(dp,-1,sizeof(dp));
	if(n==2) return 1;
	if(n==3) return 2;
	dp[2]=2;
	dp[3]=3;
	return dfs(n);     
}

int main()
{
	cout<<integerBreak(10);
	return 0;
}
