#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(a<b) swap(a,b);
	return a%b==0?b:gcd(b,a%b);
}
int main()
{
	int t;cin>>t;int n,res;
	while(t--)
	{
		cin>>n;
		res=0;
		vector<int> arr(n);
		vector<int> dp(n,1);
		for(int i=0;i<n;++i)cin>>arr[i];
		dp[0]=1;
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<i;++j)
			{
				if(gcd(arr[i],arr[j])!=1)
				{
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		for(int i=0;i<n;++i)
		{
			res=max(res,dp[i]);
			//cout<<dp[i]<<" "; 
		} 
		cout<<res<<endl;
	}
	return 0;
}
