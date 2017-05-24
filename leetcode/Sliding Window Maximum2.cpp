#include<bits/stdc++.h>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	deque<int> indexq;
	vector<int> res;
	for(int i=0;i<nums.size();++i)
	{
		if(!indexq.empty() && i-k==indexq.front()) indexq.pop_front();
		while(!indexq.empty() && nums[i]>=nums[indexq.back()])
		indexq.pop_back();
		indexq.push_back(i);
		if(i>=k-1)res.push_back(nums[indexq.front()]);
	}
	for(auto i:res)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return res;
}
int main()
{
	int a[8] = {1,3,-1,-3,5,3,6,7};
	vector<int> t(a,a+8);
	maxSlidingWindow(t,3);
	return 0;
}
