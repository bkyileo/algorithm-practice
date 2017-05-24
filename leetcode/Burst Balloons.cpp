#include<bits/stdc++.h>
using namespace std;
// ½âÌâÄ£°å
 
int maxCoins(vector<int>& nums) {

	nums.insert(nums.begin(),1);
	nums.push_back(1);
	int len=nums.size();
	vector< vector<int> > dp(len,vector<int>(len,0));
	for(int L=2;L<len;++L)
	{
		for(int left=0;left+L<len;++left)
		{
			int right=left+L;
			for(int k=left+1;k<right;++k)
				dp[left][right]=max(dp[left][right],dp[left][k]+dp[k][right]+nums[left]*nums[k]*nums[right]);
		}
	}
	for(auto i:dp)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return dp[0][len-1];
}

int main()
{
	vector<int> t{3, 1, 5, 8};
	cout<<maxCoins(t)<<endl;
}
