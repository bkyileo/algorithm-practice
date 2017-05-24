//Kth Largest Element in an Array

#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
	
	make_heap(nums.begin(),nums.end());
	while(--k)
	{
		pop_heap (nums.begin(),nums.end()); nums.pop_back();
    }
    return nums.front();   
}

int main()
{
	int a[5]={1,3,5,4,2};
	vector<int> b(a,a+5);
	cout<<findKthLargest(b,2)<<endl;
	return 0;
}
