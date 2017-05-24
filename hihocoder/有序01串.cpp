// hihoder ÓÐÐò01´®
#include<bits/stdc++.h>
using namespace std;
int cal(string s,int i)
{
	int res=0;
	for(int j=0;j<s.length();++j)
	{
		if(j<i&&s[j]!='0')res++;
		if(j>i&&s[j]!='1')res++;
	}
	return res;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		int res=INT_MAX;
		for(int i=0;i<s.length();++i)
		{
			res=min(res,cal(s,i));
		}
		cout<<res<<endl;
	} 
	return 0;
} 
