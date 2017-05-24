//Chef and his daily routine 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		string t(s);
		sort(s.begin(),s.end());
		bool f=true;
		for(int i=0;i<s.length();++i)
		{
			if(t[i]!=s[i])f=false;
		}
		if(f)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
} 
