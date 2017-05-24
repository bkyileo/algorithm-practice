#include<bits/stdc++.h>
using namespace std;
const int mod =1e9+7;
int nextt[300003];
bool mask[300003];
int dp[300003];
void solve()
{
	memset(nextt,0,sizeof(nextt));
	memset(dp,0,sizeof(dp));
	memset(mask,false,sizeof(mask));
	string a,b;
	cin>>a>>b;
	nextt[0]=0;
	int i=1,j=0;
	while(i<b.length())
	{
		if(b[i]==b[j])
		{
			j++;nextt[i]=j;i++;
		}
		else
		{
			if(nextt[j]!=0)j=nextt[j];
			else{nextt[i]=0;++i;}
		}
	}
	i=0;j=0;
	while(i<a.length())
	{
		if(a[i]==b[j])
		{
			i++;j++;
			if(j==b.length())
			{mask[i-j]=true;j=nextt[j-1];}
		}
		else
		{
			if(j!=0)j=j=nextt[j-1];
			else{i++;}
		}
	}
	int res=0;
	dp[0]=mask[0]==true?1:0;
	for(int i=1;i<a.length();++i)
	{
		dp[i]=dp[i-1];
		if(mask[i])dp[i]+=1;
		if(mask[i]&&i>=b.length())dp[i]+=dp[i-b.length()];
		dp[i]=dp[i]%mod;
	}
	cout<<dp[a.length()-1]<<endl;
}

int main()
{
	int n;cin>>n;
	while(n--)
	{
		solve();
	}
	return 0;
}
