// spoj ACODE - Alphacode
#include<bits/stdc++.h>
using namespace std;
int main()
{
	while(1)
	{
		string s;
		cin>>s;
		if(s=="0")
		{
			return 0;	
		}
		else
		{
			vector<long long> dp(s.length()+1,0);
			dp[0]=1;
			for(int i=1;i<=s.length();++i)
			{
				if(s[i-1]!='0')
					dp[i]+=dp[i-1];
				//if(i>1 && s.substr(i-2,2)<="26" && s.substr(i-2,2)>="10")
				if(i>1)
				{
					if(s[i-2]=='1')
						dp[i]+=dp[i-2];
					if(s[i-2]=='2' && s[i-1]<='6')
						dp[i]+=dp[i-2];
				}
					
			}
			/*
			for(auto i:dp)
			cout<<i<<" ";
			cout<<endl;
			*/
			if(dp[s.length()]!=0)
			cout<<dp[s.length()]<<endl;
			else
			cout<<1<<endl;
		}
	}
} 
