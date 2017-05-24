/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int> q;
    vector<int> res;
    for(int i=0;i<nums.size();++i)
    {
    	if(q.size()<k)
    	{
    		q.insert(nums[i]);
		}
    	if(q.size()==k)
    	{
    		res.push_back(*q.rbegin());
    		q.erase(q.find(nums[i-k+1]));
		}
	}
		 
	return res;
}
int main()
{
	int a[8] = {1,3,-1,-3,5,3,6,7};
	vector<int> t(a,a+8);
	maxSlidingWindow(t,3);
	return 0;
}
