#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define mod 100000007 
vector<ll>prime ;
vector<ll> sq ;
bool mark[1000009] ;
void make()
{
	mark[0] = mark[1] = 1 ;
	for(int i = 2;i< 10009;i++)
	{
		if(!mark[i])
		{
			for(int j = i*i;j<1000009;j+=i)
				mark[j] = 1 ;
		}
	}
	for(int i = 2;i<1000009;i++)
	{
		if(!mark[i]) prime.push_back(i) ;
	}
}
 
int main()
{
 
	make() ;
	int t ;
	cin>>t ;
	while(t--)
	{
		ll n ;
		cin>>n ;
		ll arr[n] ;
		for(int i = 0;i<n;i++) cin>>arr[i] ;
		ll ans = -1ll ;
		for(int i = 0;i<n-1;i++)
		{
			for(int j= i+1;j<n;j++)
			{
				if(arr[j]==1ll) continue ;
				ll g = __gcd(arr[i],arr[j]) ;
				if(g>1ll) {ans = g ; break ;}
			}
		}
		for(int i = 0;i<n;i++)
		{
			for(int j =0;prime[j]*prime[j]<=arr[i]  && j<prime.size(); j++)
			{
				if(arr[i]%prime[j] ==0ll )
				{
					arr[i] = arr[i]/prime[j] ;
					//已经除以素数了 
					if(arr[i]%prime[j] == 0ll) {ans = prime[j] ; break;}
				}
			}
			ll p = sqrt(arr[i]) ;
			if(p > 1ll && p*p == arr[i]) ans= p ;
			if(ans!=-1) break ;
		}
		cout<<ans<<endl ;
	}
}
