#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int n;cin>>n;
	int nums;
	while(n--)
	{
		cin>>nums;
		vector<int> arr(nums);
		for(int i=0;i<nums;++i)
		{
			cin>>arr[i];
		}
		
		sort(arr.begin(),arr.end());
		
		if(arr[0]<arr[1]-1)cout<<arr[0]<<endl;
		else if(arr[nums-1]>arr[nums-2]+1)cout<<arr[nums-1]<<endl;
		else
		{
			for(int i=0;i<nums-1;++i)
			{
				if(arr[i]==arr[i+1]){
					cout<<arr[i]<<endl;
					break;
				}
			}
		}
	}
	 
} 
