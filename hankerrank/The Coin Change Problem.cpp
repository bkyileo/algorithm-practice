#include<bits/stdc++.h>
using namespace std;
long long slove();
//int dfs(int n,vector<int>& dp,vector<int>& arr);
int main()
{
	cout<<slove()<<endl;
	return 0;
}
long long slove()
{
	int n,m;
	cin>>n>>m;
	vector<int> arr(m);
	for(int i=0;i<m;++i)
	{
		cin>>arr[i];	
	}
	sort(arr.begin(),arr.end());
	vector<long long> dp(n+1);
	dp[0]=1;
	for(int j=0;j<m;++j)
	{
		for(int i=0;i<=n;i++)
		{
			if(arr[j]+i>n)break;
			else
			{
				dp[i+arr[j]]+=dp[i];
			}
		}
	}
	//for(auto i:dp)cout<<i<<" ";cout<<endl;
	return dp[n];
}
/*
int slove()
{
	int n,m;
	cin>>n>>m;
	vector<int> arr(m);
	for(int i=0;i<m;++i)
	{
		cin>>arr[i];
	}
	vector<int> dp(n+1,-1);
	return dfs(n,dp,arr);
}
int dfs(int n,vector<int>& dp,vector<int>& arr)
{
	if(n<0)return 0;
	if(n==0)return 1;
	if(dp[n]!=-1)return dp[n];
	int res=0;
	for(int i=0;i<arr.size();++i)
	{
		res+=dfs(n-arr[i],dp,arr);
	}
	dp[n]=res;
	return dp[n];
}

/*
int slove()
{
	int n,m;
	cin>>n>>m;
	vector<int> arr(m);
	for(int i=0;i<m;++i)
	{
		cin>>arr[i];	
	}
	sort(arr.begin(),arr.end());
	vector<int> dp(n+1);
	dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(arr[j]>i)break;
			else
			{
				dp[i]+=dp[i-arr[j]];
			}
		}
	}
	for(auto i:dp)cout<<i<<" ";cout<<endl;
	return dp[n];
}
*/
