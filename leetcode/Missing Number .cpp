#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
	int length=nums.size();
	int sum=(length+1)*length/2;
	for(auto i:nums)
	{
		sum-=i;
	}
	return sum;        
}

int main()
{
	vector<int> t{0,1,3};
	cout<<missingNumber(t)<<endl;
}
