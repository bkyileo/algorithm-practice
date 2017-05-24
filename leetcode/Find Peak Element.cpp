#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>& nums) {
	int l,r,mid;
	l=0;r=nums.size()-1;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(nums[mid]<=nums[l]&&nums[l]>nums[r])r=mid-1;
		else
		{
			l=mid;	
		}
		//cout<<l<<" "<<r<<endl;
	}
	if(nums[l]>nums[l+1]&&(l==0||nums[l]>nums[l-1]))return l;
	else return r;
}
int main()
{
	vector<int> arr={5,4,3,2,1};
	cout<<findPeakElement(arr);
	return 0;
}
