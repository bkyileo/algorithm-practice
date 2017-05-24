#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
	int i,j;
	i=0;j=0;
	while(j<nums.size())
	{
		while(nums[j]==nums[i])j++;
		nums[++i]=nums[j];
	}
	//for(auto i:nums)cout<<i<<" ";cout<<endl;
	return i;
}
int removeElement(vector<int>& nums, int val) {
	int i,j;
	i=0;j=0;
	while(j<nums.size())
	{
		if(nums[j]==val)j++;
		nums[i++]=nums[j++];
	}
	for(auto i:nums)cout<<i<<" ";cout<<endl;
	return i;
}
int main()
{
	vector<int> arr={1,2,3,4,5};
	cout<<removeElement(arr,4)<<endl;
	return 0;
}
