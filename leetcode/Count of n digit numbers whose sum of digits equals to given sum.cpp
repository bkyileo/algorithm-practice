//geekforgeek
//Count of n digit numbers whose sum of digits equals to given sum
//http://www.geeksforgeeks.org/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/ 

#include<bits/stdc++.h>
using namespace std;

int solve(int n,int sum)
{
	vector<vector<int>> dp(n,vector<int>(sum,0));
	//n––sum¡– 
	for(int i=0;i<n;++i)
	{
		dp[i][0]=1; 
	}
	for(int i=0;i<min(sum,10);++i)
	{
		dp[0][i]=1;
	}
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<sum;++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl; 
	}
	
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<sum;++j)
		{
			//∞— dp[n-1][x] where  sum-9<= x <=sum
			for(int k=0;k<=9;++k)
			{
				if(j-k>=0)
					dp[i][j] += dp[i-1][j-k];
			}
		} 
	}
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<sum;++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl; 
	}
	
	return dp[n-1][sum-1];
}

int main()
{
	cout<<solve(3,5)<<endl;
	return 0;
}
