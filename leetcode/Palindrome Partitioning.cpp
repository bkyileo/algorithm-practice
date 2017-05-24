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
void backtrace(vector< string >& res,int start,int end,int length,string s)
{
	if(start == end) return;
	if(start < end && palindrome(s.substr(start,end-start)))
	{
		//cout<<s.substr(start,end-start)<<endl;
		res.push_back(s.substr(start,end-start));
	}
	//这样走多走了一步 
	if(end<length)
	{
		cout<<"here"<<endl;
		backtrace(res,start,end+1,length,s);
	}
	if(start<end)
	{
		backtrace(res,start+1,end,length,s);
	}
}
vector< string > partition(string s) {
	vector< string > res;
	if(s.length()==0)return res;
	backtrace(res,0,1,s.length(),s);
	for(int i=0;i<res.size();++i)
		cout<<res[i]<<" ";
	cout<<endl;
	return res;
} 

int main()
{
	partition("aab");
	return 0;
}
