#include<bits/stdc++.h>
using namespace std;
int findMaxForm(vector<string>& strs, int m, int n) {
	//m-0,n-1
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(auto i:strs)
	{
		int a=0,b=0;
		for(auto j:i)
		{
			if(j=='0')a++;
			if(j=='1')b++;
		}
		for(int j=m;j>=a;j--)
		for(int k=n;k>=b;k--)
		{
			dp[j][k]=max(dp[j][k],dp[j-a][k-b]+1);
		}
	}
	/*
	for(auto i:dp)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
	*/
	return dp[m][n];
}
int main()
{
	//["10","0001","111001","1","0"]
	vector<string> strs={"10","0001","111001","1","0"};
	cout<<findMaxForm(strs,5,3)<<endl;
	return 0;
}
