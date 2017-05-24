#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
	int l,r,mid;
	int n=nums.size();
	l=0;r=n-1;
	while(l<r)
	{
		cout<<l<<" "<<r<<endl;
		mid=(l+r)/2;
		if(nums[mid]>nums[r])l=mid+1;
		else if(nums[mid]==nums[r])
		{
			l++;
			r--;	
		}
		else
		r=mid; 
	}
	return min(nums[l],nums[r]);
}
int main()
{
	vector<int> arr={3,4,5,1,2,3};
	cout<<findMin(arr)<<endl;
}
