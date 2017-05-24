#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int> arr,int curr,int rest,int s,int& res)
{
	//cout<<i<<" "<<curr<<" "<<rest<<endl;
	if(abs(curr)+abs(rest)<abs(s))return ;
	if(i==arr.size()){
		if(curr==s)res++;
		return ;
	}
	rest-=arr[i];
	curr+=arr[i];
	dfs(i+1,arr,curr,rest,s,res);
	curr-=2*arr[i];
	dfs(i+1,arr,curr,rest,s,res);
}
int findTargetSumWays2(vector<int>& nums, int S) {
	int all=0;
	for(auto i:nums)all+=i;
	int res=0;
	dfs(0,nums,0,all,S,res);
	return res;       
}
int findTargetSumWays(vector<int>& nums, int S) {
    int sum = 0; 
    for(auto i: nums) sum+=i;
    vector<int> dp(2*sum+1,0);
    dp[0+sum] = 1;
    for(int i = 0; i<nums.size(); i++){
        vector<int> next(2*sum+1,0);
        for(int k = 0; k<2*sum+1; k++){
            if(dp[k]!=0){
                next[k + nums[i]] += dp[k];
                next[k - nums[i]] += dp[k];
            }
        }
        for(int k = 0; k<2*sum+1; k++) 
        dp[k] = next[k];
    }
    return dp[sum+S];
}
int main()
{
	vector<int>a={1};
	cout<<findTargetSumWays(a,3)<<endl;
	return 0;
} 
