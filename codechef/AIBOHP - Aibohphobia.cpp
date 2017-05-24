//spoj AIBOHP - Aibohphobia 与hihocoder不同在于它只能增加 
#include<bits/stdc++.h>
using namespace std;
int dp[6105][6105];
int lcs(string a,string b)
{
	int res=0;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=a.length();++i)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=b.length();++i)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=a.length();++i)
	for(int j=1;j<=b.length();++j)
	{
		if(a[i-1]==b[j-1])
		{
			//cout<<a[i]<<" "<<b[j]<<endl; 
			dp[i][j]=dp[i-1][j-1]+1;
		}
		else
		{
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
		if(i+j==a.length()+2||i+j==a.length()+1)
			res=max(res,dp[i][j]);
	}
	/*
	for(int i=0;i<=a.length();++i)
	{
		for(int j=0;j<=b.length();++j)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
	return a.length()-dp[a.length()][a.length()];
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		string a,b;
		a = s;
		b.assign(s.rbegin(), s.rend());
		//cout<<a<<" "<<b<<endl;
		cout<<lcs(a,b)<<endl;
	}
	return 0;
} 

 
