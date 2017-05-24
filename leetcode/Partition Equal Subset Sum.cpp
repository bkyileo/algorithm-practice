#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums) {
	int all=0;
	for(auto i:nums)all+=i;
	if(all%2)return false;
	vector<bool> dp(all+1,false);
	vector<bool> next;
	dp[0]=true;
	for(auto i:nums)
	{
		next=vector<bool>(all+1,0);
		for(int j=0;j<dp.size();++j)
		{
			if(dp[j])
			{
				next[j]=true;
				next[j+i]=true;
			}
		}
		dp=next;
	}
	return dp[all/2];	      
}
int main()
{
	vector<int> arr={1,5,11,5};
	cout<<canPartition(arr)<<endl;
	return 0;
}
