#include<bits/stdc++.h>
using namespace std;
bool repeatedSubstringPattern(string s) {
	vector<int> dp(s.length(),0);
	int i=1,j=0;
	while(i<s.length())
	{
		if(s[i]==s[j])
		{
			j++;
			dp[i]=j;
			i++;
		}
		else
		{
			if(j!=0)j=dp[j-1];
			else
			{
				++i;
			}
		}
	}
	int n=s.length()-1;
	//for(auto i:dp)cout<<i<<" ";cout<<endl;
	return dp[n]&&dp[n]%(n-dp[n]+1)==0;
}
int main()
{
	//"aabaaba"
	cout<<repeatedSubstringPattern("abcdeabcdeabcdeabcde");
	return 0;	
} 
