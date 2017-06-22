#include<bits/stdc++.h>
using namespace std;
void slove()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vector<int>arr(n);
		for(int i=0;i<n;++i)cin>>arr[i];
		int conti=0;
		int local=0;
		int unconti=0;
		for(int i=0;i<n;++i)
		{
			if(arr[i]>0)unconti+=arr[i];
			local=max(local+arr[i],arr[i]);
			conti=max(conti,local);
		}
		if(unconti==0)
		{
			unconti = -1e9;
			conti = -1e9;
			for(auto i:arr)
			{
				unconti=max(unconti,i);
				conti=max(conti,i);
			}
		}
		cout<<conti<<" "<<unconti<<endl;
	}
}
int main()
{
	slove();
	return 0;
}
