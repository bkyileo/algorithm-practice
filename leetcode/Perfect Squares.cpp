// leetcode Perfect Squares

#include<bits/stdc++.h>
using namespace std;

int numSquares(int n) {
//	int dp[100000];
	static vector<int> dp;
	dp.push_back(0);
	
    for(int i=1;i<=n;++i)
    {
    	dp.push_back(INT_MAX);
//		dp[i]=10000;
    	if(sqrt(i)*sqrt(i)==i)
    	{
     		dp[i]=1;
		}	
     	else
     	{
     		for(int j=1;j<i;j++)
     		{
     			dp[i]=min(dp[i],dp[j]+dp[i-j]);
			 }
		}
	}

	return dp[n];
}
int main()
{
	cout<<numSquares(9975)<<endl;

	return 0;
 } 
 
