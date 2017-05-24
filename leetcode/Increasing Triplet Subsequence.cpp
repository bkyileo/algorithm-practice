#include<bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
	
	if(nums.size()<3) return false;
	int i=-1,j=-1 ;
	for(int k=1;k<nums.size();++k)
	{
		if(nums[k]<=nums[k-1])
		{
			if(i==-1)
				continue;
			if(nums[j]<nums[k])
				i=k;
		}
		else if(i== -1)
		{
			j=k-1;
			i=k;
		}
		else if(nums[k]>nums[i])
		{
			return true;
		}
		else
		{
			i=k;
		}
	}
	return false;       
}
int main()
{
	vector<int> a{5,1,5,5,2,5,4};
	cout<<increasingTriplet(a)<<endl;
} 
