#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(a<b)swap(a,b);
	return a%b==0?b:gcd(b,a%b);
}
int main()
{
	//cout<<gcd(10,12)<<endl;
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vector<long long> arr(n);
		for(int i=0;i<n;++i)cin>>arr[i];
		long long res=1e18;
		//sort(arr.begin(),arr.end());
		for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		res=min(res,(arr[i]*arr[j]/gcd(arr[i],arr[j])));
		cout<<res<<endl;
	}
	return 0;
}
