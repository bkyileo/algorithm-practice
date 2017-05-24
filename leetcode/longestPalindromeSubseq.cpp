#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n=s.length();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;++i)
    dp[i][i]=1;
    for(int l=1;l<n;l++)
    {
        for(int left=0;left+l<n;++left)
        {
        	dp[left][left+l]=max(dp[left][left+l-1],dp[left+1][left+l]);  
            if(s[left]==s[left+l])
            {
                dp[left][left+l]=max(dp[left+1][left+l-1]+2,dp[left][left+l]);
            }
        }
    }
    int res=0;
    for(auto i:dp)
	{
		for(auto j:i)
		{
			//cout<<j<<" ";
			res=max(res,j);			
		}
		//cout<<endl;
	}
    return res;
}
int main()
{
	cout<<longestPalindromeSubseq("aaaba");
} 
