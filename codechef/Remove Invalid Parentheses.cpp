#include<bits/stdc++.h>
using namespace std;
void dfs(int l,int r,string s,string curr,int i,set<string>& res)
{
	if(l==0&&r==0&&i==s.length())
	{
		int rml=0;
		int rmr=0;
		for(int i=0;i<curr.length();++i)
		{
			if(curr[i]=='(')rml++;
			if(curr[i]==')')
			{
				if(rml>0)rml--;
				else rmr++;
			}
		}
		if(rml==rmr&&rmr==0)res.insert(curr);
		return ;
	}
	if(i==s.length())return ;
	if(s[i]==')'&&r>0)
	{
		dfs(l,r-1,s,curr,i+1,res);
		dfs(l,r,s,curr+s[i],i+1,res);
	}
	if(s[i]=='('&&l>0)
	{
		dfs(l-1,r,s,curr,i+1,res);
		dfs(l,r,s,curr+s[i],i+1,res);
	}
	dfs(l,r,s,curr+s[i],i+1,res);
}
vector<string> removeInvalidParentheses(string s) {
	set<string> tp;
	int rml=0;
	int rmr=0;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='(')rml++;
		if(s[i]==')')
		{
			if(rml>0)rml--;
			else rmr++;
		}
	}
	dfs(rml,rmr,s,"",0,tp);
	//for(auto i:tp)cout<<i<<endl;
	//cout<<endl;
	vector<string> res;
	return res;
}
int main()
{
	removeInvalidParentheses(")()(");
	
	removeInvalidParentheses("((())()");
	return 0;
} 
