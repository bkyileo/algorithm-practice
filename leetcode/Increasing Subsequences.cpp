#include<bits/stdc++.h>
using namespace std;
void dfs(set<vector<int>>& res,vector<int> curr,int index,vector<int> nums)
{
	if(index==nums.size())
	{
		res.insert(curr);
		return ;
	}
	if(curr.size()==0||nums[index]>=curr[curr.size()-1])
	{
		curr.push_back(nums[index]);
		dfs(res,curr,index+1,nums);
		curr.pop_back();
		dfs(res,curr,index+1,nums);
	}
	else
	{
		dfs(res,curr,index+1,nums);
	}
	

}
vector<vector<int>> findSubsequences(vector<int>& nums) {
	set<vector<int>> res;
	vector<int> curr;
	dfs(res,curr,0,nums);
	vector<vector<int>> ress;
	for(auto i:res)
	{
		if(i.size()>1)
		{
			ress.push_back(i);
			/*
			for(auto j:i)
			{
				cout<<j<<" ";
			}
			cout<<endl;
			*/
		}
	}
	return ress;      
}
int main()
{
	vector<int> arr={4,6,7,7};
	findSubsequences(arr);
}
