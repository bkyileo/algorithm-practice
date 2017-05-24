// spoj Advanced Fruits
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		int len1=a.length();
		int len2=b.length();
		vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
		for(int i=1;i<=len1;++i)
		for(int j=1;j<=len2;++j)
		{
			if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
		//cout<<dp[len1][len2]<<endl;
		vector<char> res(len1+len2-dp[len1][len2]);
		int curr=len1+len2-dp[len1][len2]-1;
		while(len1>0&&len2>0)
		{
			if(a[len1-1]==b[len2-1])
			{
				res[curr]=a[len1-1];
				len1--;len2--;curr--;
			}
			else if(dp[len1-1][len2]>dp[len1][len2-1])
			{
				res[curr]=a[len1-1];
				curr--;len1--;
			}
			else
			{
				res[curr]=b[len2-1];
				curr--;len2--;
			}
		}
		while(len1>0)
		{
			res[curr]=a[len1-1];
			curr--;len1--;
		} 
		while(len2>0)
		{
			res[curr]=b[len2-1];
			curr--;len2--;
		}
		for(auto i:res)cout<<i;cout<<endl;
	}
	return 0;
}
