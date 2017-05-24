//hihocoder »ØÎÄ×Ö·û´®
#include<bits/stdc++.h>
using namespace std;
int edit_distance(string a,string b)
{
	int res=INT_MAX;
	int dp[105][105];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=a.length();++i)
	{
		dp[i][0]=i;
	}
	for(int i=0;i<=b.length();++i)
	{
		dp[0][i]=i;
	}
	for(int i=1;i<=a.length();++i)
	for(int j=1;j<=b.length();++j)
	{
		if(a[i-1]==b[j-1])
		{
			//cout<<a[i]<<" "<<b[j]<<endl; 
			dp[i][j]=dp[i-1][j-1];
		}
		else
		{
			dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
		}
		if(i+j==a.length()||i+j==a.length()+1)
		res=min(res,dp[i][j]);
	}
	/*
	for(int i=0;i<=a.length();++i)
	{
		for(int j=0;j<=b.length();++j)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
	return res;
}

int main()
{
	string s;cin>>s;
	string a,b;
	a = s;
	b.assign(s.rbegin(), s.rend());
	//cout<<a<<" "<<b<<endl;
	cout<<edit_distance(a,b)<<endl;
	return 0;
} 


