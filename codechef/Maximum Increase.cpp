#include<bits/stdc++.h>
using namespace std;
int main()
{
	int res=0;
	int nums;
	cin>>nums;
	vector<int> arr(nums);
	for(int i=0;i<nums;++i)
	{
		cin>>arr[i];
	}
	int curr=1;
	for(int i=1;i<nums;++i)
	{
		if(arr[i]>arr[i-1])curr++;
		else
		{
			res=max(res,curr);
			curr=1;
		}
	}
	res=max(res,curr);
	cout<<res<<endl;
} 
