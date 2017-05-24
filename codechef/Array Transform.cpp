//code chef Array Transform
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int nums,k;cin>>nums>>k;vector<int> arr(nums);
		for(int i=0;i<nums;++i)
		{
			cin>>arr[i];
		}
		bool flag=false;
		for(int i=0;i<nums;++i)
		{
			int temp=0;
			for(int j=0;j<nums;++j)
			{
				if(abs(arr[i]-arr[j])%(k+1)==0)continue;
				else temp++;
			}
			if(temp<2)flag=true;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

