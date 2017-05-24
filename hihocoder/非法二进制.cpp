// hihocoder 非法二进制数
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
	long long a=1;
	long long b=1;
	long long c=0;
	int t;cin>>t;
	while(--t)
	{
		long long tempa,tempb,tempc;
		tempa=a;tempb=b;tempc=c;
		a=(tempa+tempb)%mod;b=(tempa)%mod;c=(2*tempc+tempb)%mod;
	}
	cout<<c<<endl;
} 
