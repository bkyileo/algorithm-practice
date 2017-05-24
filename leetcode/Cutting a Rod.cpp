#include<bits/stdc++.h>
using namespace std;

int cuttingRod(vector<int> prices)
{
	if(prices.size()==0) return 0;
	vector<int> dp(prices.size(),INT_MIN);
	dp[0] = prices[0];
	for(int i=1;i<prices.size();++i)
	{
		int res=INT_MIN;
		for(int j=0;j<dp.size();++j)
		{
			res=max(dp[j]+dp[i-j-1],res);	
		}
		res=max(res,prices[i]);
		dp[i]=res;
	}
	for(int j=0;j<dp.size();++j)
		cout<<dp[j]<<" ";
	cout<<endl;
	return 0;
}

int main()
{
	int t[8]={3,5,8,9,10,17,17,20};
	vector<int> test(t,t+8);
	cuttingRod(test);
	return 0;
} 
