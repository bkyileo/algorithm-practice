#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;++i)cin>>arr[i];
		int hi=0;
		int lo=0;
		
		int next_hi=0;
		int next_lo=0;
		for(int i=1;i<n;++i)
		{
			int h2l=arr[i-1]-1;
			int l2h=arr[i]-1;
			int h2h=abs(arr[i]-arr[i-1]);
			
			next_hi=max(hi+h2h,lo+l2h);
			next_lo=max(lo,h2l+hi);
			
			hi=next_hi;
			lo=next_lo;
		}
		cout<<max(hi,lo)<<endl;
	}
	return 0;
}
