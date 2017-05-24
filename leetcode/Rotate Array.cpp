#include<bits/stdc++.h>
using namespace std;

    void rotate(vector<int>& nums, int k) {
        if(k==0) return;
        vector<int> temp;
        for(int i=0;i<k;++i)
        {
            temp.push_back(nums[nums.size()-k+i]);
        }
        for(int i=nums.size()-k-1;i>=0;--i)
        {
        	nums[i+k]=nums[i];
		}
		for(int i=0;i<temp.size();++i)
		{
			nums[i]=temp[i];
		}
    }
    int main()
    {
    	int a[7]={1,2,3,4,5,6,7};
    	vector<int> b(a,a+7);
    	rotate(b,3);
    	for(int i=0;i<7;++i)
		{
			cout<<b[i]<<" ";
		 } 
	}
