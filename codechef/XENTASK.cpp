#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	while(n--)
	{
		int nums;cin>>nums;
		vector<int> arr1(nums);
		vector<int> arr2(nums);
		for(int i=0;i<nums;++i)
		{
			cin>>arr1[i];
		}
		for(int i=0;i<nums;++i)
		{
			cin>>arr2[i];
		}
		int ct1=0;
		int ct2=0;
		for(int i=0;i<nums;++i)
		{
			if(i%2)
			{
				ct1+=arr1[i];
				ct2+=arr2[i];
			}
			else
			{
				ct1+=arr2[i];
				ct2+=arr1[i];			
			}
		}
		cout<<min(ct1,ct2)<<endl;
	}
}
