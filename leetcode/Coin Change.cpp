#include<bits/stdc++.h>
using namespace std; 
    
int coinChange(vector<int>& coins, int amount) {
	if(amount==0) return 0;
	
	vector<int> dp(amount+1,INT_MAX-1);
	dp[0]=0;
	 
	for(int i=1;i<=amount;++i)
	{
		for(auto j:coins)
		{
			if(j<=i)dp[i]=min(dp[i-j]+1,dp[i]);
		}
	}
//	for(auto i:dp)
//	{
//		cout<<i<<" ";
//	}
//	cout<<endl;
	if(dp[amount]==INT_MAX-1)
		return -1;
	return dp[amount];
}

int main()
{
	vector<int> c{2};
	cout<<coinChange(c,3)<<endl;
	return 0;
}
