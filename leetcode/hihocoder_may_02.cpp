#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	vector<int> dp(s.length(),0); 
	stack<int> stk;
	int temp;
	int count=0;

	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='(')
		{
			stk.push(i);
		}
		if(s[i]==')'&&!stk.empty())
		{
			temp=stk.top();
			stk.pop();
			
			if(temp==0)
				dp[i]=1;
			else
				dp[i]=dp[temp-1]+1;
		}
		count+=dp[i];
	}
	cout<<count<<endl;
	return 0;
}
