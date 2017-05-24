#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
	int slow=0;
	int fast=0;
	while(fast!=slow)
	{
		fast=nums[nums[fast]];
		slow=nums[slow];
	}
	fast=0;
	while(slow!=fast)
	{
		fast=nums[fast];
		slow=nums[slow];	
	}
	return fast;
} 
int main()
{
	vector<int> arr={1,3,4,2,2};
	cout<<findDuplicate(arr)<<endl;
	return 0;
}
