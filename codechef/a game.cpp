//hihocoder a game
#include<bits/stdc++.h>
using namespace std;
/*
5
1 0 2 -1 1

1 1 2  3 3 
0 0 2 -1 3 
0 0 2  2 1 
0 0 0 -1 1 
0 0 0  0 1
*/
int sums(vector<int> arr,int l,int r)
{
	int res=0;
	for(int i=l;i<=r;++i)res+=arr[i];
	return res; 
}
int main()
{
	int n;cin>>n;vector<int> arr(n);
	for(int i=0;i<n;++i)cin>>arr[i];
	vector< vector<int> > dp(n,vector<int>(n,0));
	for(int i=0;i<n;++i)dp[i][i]=arr[i];
	for(int i=0;i<n-1;++i)dp[i][i+1]=max(dp[i][i],dp[i+1][i+1]);
	//for(int i=0;i<n-2;++i)dp[i][i+2]=max(dp[i][i],dp[i+2][i+2])+min(min(dp[i][i],dp[i+2][i+2]),dp[i+1][i+1]);
	for(int L=2;L<n;++L)
	{
		for(int left=0;left+L<n;++left)
		{
			int right=left+L;
			dp[left][right]=max(sums(arr,left+1,right)-dp[left+1][right]+arr[left],sums(arr,left,right-1)-dp[left][right-1]+arr[right]);
		}
	}
	//cout<<endl;
	//for(int i=0;i<n;++i){for(int j=0;j<n;++j)cout<<dp[i][j]<<" ";cout<<endl;}
	cout<<dp[0][n-1]<<endl;
	return 0;
}
