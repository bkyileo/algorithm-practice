#include<bits/stdc++.h>
using namespace std;


int minCut(string s) {
	if(s.length()<2) return s.length();
	vector< vector<bool> >pal(s.length(),vector<bool>(s.length(),true));
	for(int i=1;i<s.length();++i)
	{
		for(int j=0;j<s.length();++j)
		{
			if(i+j>=s.length())
				break;
			pal[j][i+j]=(pal[j+1][i+j-1]&&s[j]==s[i+j]);
		}
	}
	vector<int> dp(s.length(),INT_MAX);
	for(int i=0;i<s.length();++i)
	{
		if(pal[0][i])
		{
			dp[i]=0;
		}
		else
		{
			for(int j=0;j<i;++j)
				{
					if(pal[j+1][i])
						dp[i]=min(dp[i],1+dp[j]);
				}
		}
	}
//	for(int i=0;i<s.length();++i)
//	{	
//		for(int j=0;j<s.length();++j)
//			cout<<pal[i][j]<<" ";
//		cout<<endl;
//	}
//	for(int i=0;i<s.length();++i)
//		cout<<dp[i]<<" ";
//	cout<<endl;
	
	return dp[s.length()-1];
}
 
int main()
{
	minCut("");
}
