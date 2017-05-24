#include<bits/stdc++.h>
using namespace std;

int numDistinct(string s, string t) {
		if(t.length()>s.length())return 0;
        vector< vector<int> > dp(t.length()+1,vector<int>(s.length()+1,0));
		for(int i=0;i<s.length()+1;++i)
        dp[0][i]=1;
              
        for(int i=1;i<t.length()+1;++i)
        for(int j=1;j<s.length()+1;++j)
        {
            if (t[i-1]==s[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];  
        	}
			else
                dp[i][j]=dp[i][j-1]; 
        }
        
        return dp[t.length()][s.length()];
}
int main()
{
	cout<<numDistinct("ccc","c")<<endl;
}
