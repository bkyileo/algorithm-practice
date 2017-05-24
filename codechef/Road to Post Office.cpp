//code forces Road to Post Office 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll d,k,a,b,t;
	cin>>d>>k>>a>>b>>t;
	if(d<=k)
	{
		cout<<d*a<<endl;
	} 
	else if(k*a+t>b*k)
	{
		cout<<(d-k)*b+k*a<<endl;
	}
	else
	{
		ll basetime=(d/k)*k*a+(d/k-1)*t;
		cout<<min(d%k*b,d%k*a+t)+basetime<<endl;
	}
	return 0;
}
