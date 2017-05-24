#include<bits/stdc++.h>
using namespace std;
bool palindrome(string s)
{
	if(s.length()==0)
		return false;
	for(int i=0;i<s.length()/2;++i)
		if(s[i]!=s[s.length()-1-i])
			return false;
	return true;
}

void backtrace(vector< vector<string> >&res,vector<string> temp,string s)
{
	if(s.length()==0) 
	{
		res.push_back(temp);
		return ;
	}
	for(int i=1;i<=s.length();++i)
	{

		if(palindrome(s.substr(0,i)))
		{
			temp.push_back(s.substr(0,i));
			backtrace(res,temp,s.substr(i));
			temp.pop_back();
		}
	}
}

vector< vector<string> >partition(string s) {
	vector< vector<string> > res;
	if(s.length()==0) return res;
	vector<string> temp;
	backtrace(res,temp,s);
	return res;
} 

int main()
{
	partition("aab");
	return 0;
}
