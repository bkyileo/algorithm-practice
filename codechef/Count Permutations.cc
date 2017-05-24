#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long pow(int a)
{
	if(a==0)return 1;
	long long tp=pow(a/2);
	if(a%2)return ((tp%mod)*(tp%mod)*2)%mod;
	return ((tp%mod)*(tp%mod))%mod;
}
int main()
{
	int n;cin>>n;
	while(n--)
	{
		int a;cin>>a;
		if (a==1)cout<<0<<endl;
		else cout<<pow(a-1)-2<<endl;
	}
}
