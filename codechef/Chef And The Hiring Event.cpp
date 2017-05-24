// code chef Chef And The Hiring Event
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[20];
void init()
{
	ll s=5;
	for(int i=0;i<20;++i)
	{
		dp[i]=s;
		s*=5;
	}
}
ll slove(ll q)
{
	ll res=0;
	ll tp=0;
	for(int i=19;i>=0;--i)
	{
		if(q>dp[i])
		{
			ll t=q/dp[i];
			//cout<<" i t: "<<i<<" "<<t<<endl;
			res += 2*t*(ll)pow(10,i+1);
			q=q%dp[i];
			if(q==0&&i>=0)
			{
				res -= 2*(ll)pow(10,i+1);
				tp=i+1;
				break;	
			}
		}
	}
	if(q>0)
		res+=q*2-2;
	else
	{
		while(tp--)
		{
			res+=8*(ll)pow(10,tp);
		}		
	}
	return res;
}
int main()
{
	init();
	ll t;cin>>t;
	while(t--)
	{
		ll k;
		cin>>k;
		cout<<slove(k)<<endl;
	}
	return 0;	
}

