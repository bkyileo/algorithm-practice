#include<bits/stdc++.h>
using namespace std;
int findMaxLength(vector<int>& nums) {
		if(nums.size()<2) return 0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)nums[i]=-1;
        }
        for(int i=1;i<nums.size();++i)
		{
        	nums[i]+=nums[i-1];
		} 
        map<int,int>mp;
        int res=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();++i)
        {
            if(mp.find(nums[i])==mp.end())mp[nums[i]]=i;
            else
            {
                res=max(res,i-mp.find(nums[i])->second);
            }
        }
        return res;
}
int main()
{
	vector<int> arr={-1,1,-1};
	cout<<findMaxLength(arr)<<endl;
	return 0;
}
