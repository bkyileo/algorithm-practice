/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ¡İ s. If there isn't one, return 0 instead.
For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/
#include<bits/stdc++.h>
using namespace std;
int minSubArrayLen(int s, vector<int>& nums) {
    int sum=0;
    int start=0;
    int end=0;
    int res=INT_MAX;
	while(end<nums.size())
	{
		cout<<sum<<endl;
		if(sum<s)
		{
			sum+=nums[end++];
		}
		while(sum>=s)
		{ 
			res=min(end-start,res);
			sum-=nums[start++];
		}
	}
	return res;
}

int main()
{
	int a[6]={2,3,1,2,4,3};
	vector<int> t(a,a+6);
	cout<<minSubArrayLen(7,t);
	return 0;
}
