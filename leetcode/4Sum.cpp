#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	int n=nums.size();
	if(n<4)return res;
	sort(nums.begin(),nums.end());
	for(int i=0;i<n-3;++i)
	{
		if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)break;
		if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target)continue;
		if(i>0&&nums[i]==nums[i-1])continue;
		for(int j=i+1;j<n-2;++j)
		{
			if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)break;
			if(nums[i]+nums[j]+nums[n-1]+nums[n-2]<target)continue;
			if(j>1+i&&nums[j]==nums[j-1])continue;
			int l=j+1;int r=n-1;
			while(l<r)
			{
				if(nums[i]+nums[j]+nums[l]+nums[r]>target)r--;
				else if(nums[i]+nums[j]+nums[l]+nums[r]<target)l++;
				else
				{
					vector<int> arr={nums[i],nums[j],nums[l],nums[r]};
					res.push_back(arr);
                    do{l++;}while(nums[l]==nums[l-1]&&l<r);
                    do{r--;}while(nums[r]==nums[r+1]&&l<r);
				}	
			}
		}	
	}
	return res;        
}
int main()
{
	vector<int> arr={0,0,0,0};
	vector<vector<int>> res=fourSum(arr,0);
	for(auto i:res)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
	return 0;
} 
