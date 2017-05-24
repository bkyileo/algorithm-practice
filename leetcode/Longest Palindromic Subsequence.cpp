//DP solution for Longest Palindromic Subsequence  注意 这里是最长连续回文字串 
#include<bits/stdc++.h>
using namespace std;

string Pal_sub(string s)
{
	int len=s.length();
	
	vector< vector<bool> > dp(len,vector<bool>(len,true));
	//dp[i][j] 表示从 index i -> index j 的子结构是否回文
	for(int j=1;j<len;++j) 
	{
		for(int i=0;i<len;++i)
		{
			if(i+j<len)
			{
				if(dp[i+1][i+j-1] && s[i] == s[i+j])
					dp[i][i+j] = true;
				else
					dp[i][i+j] = false;
				cout<<i<<"-"<<i+j<<"-"<<(s[i] == s[i+j])<<" "<<dp[i][i+j]<<"  ";
			}
			//3,7 -> 4,6 && [3]==[7]
			//4,5 -> 5,4 && [4]==[5]
		} 
		cout<<endl;
	}
	for(int i=0;i<len;++i)
	{
		for(int j=0;j<len;++j)
		{
			if(i<=j)
				cout<<dp[i][j]<<" ";
			else
				cout<<"  ";
		}
		cout<<endl;
	}
	return "1";	 
}
/*
	求不连续的最优子结构 
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
*/ 

int main()
{
	Pal_sub("BBABCBCAB");
	return 0;
}

