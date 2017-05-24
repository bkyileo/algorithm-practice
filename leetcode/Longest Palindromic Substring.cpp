#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
	int n=s.length();
	string res="";
	res+=s[0];//初始值有问题 
	vector<vector<bool>> dp(n,vector<bool>(n,false));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i>=j)dp[i][j]=true;	
		}
	}
	for(int len=1;len<n;++len)
	{
		for(int i=0;i+len<n;++i)
		{
			if(s[i]==s[i+len]&&dp[i+1][i+len-1])
			{
				dp[i][i+len]=true;
				res=s.substr(i,len+1);
			}	
		}
	}
	/*
	for(auto i:dp)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;	
	}
	*/
	return res;
}
int main()
{
	cout<<longestPalindrome("babad")<<endl;
	return 0;
} 
