#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums) {
	int reach=0;
	for(int i=0;i<nums.size();++i)
	{
		if(reach>=i)
		{
			reach=max(reach,i+nums[i]);
		}
	}
	return reach>=nums.size()-1;        
}
int jump(vector<int>& nums) {
	int res=0;
	int newreach=0;
	int oldreach=0;
	for(int i=0;i<nums.size();++i)
	{
		if(i>oldreach)
		{
			res++;
			oldreach=newreach;
			
		}
		newreach=max(newreach,i+nums[i]);	
	} 
	return res;      
}
int main()
{
	vector<int> arr1={2,3,1,1,4};
	/*
	vector<int> arr2={3,2,1,0,4};
	cout<<canJump(arr1)<<endl;
	cout<<canJump(arr2)<<endl;
	*/
	cout<<jump(arr1)<<endl;
	return 0;
} 
