#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		bool flag=true;
		int len=s.length();
		for(int i=0;i<=len/2;++i)
		{
			if(s[i]==s[len-i-1])
			{
				if(s[i]=='.'){s[i]='a';s[len-i-1]='a';}
			}
			else
			{
				if(s[i]=='.')s[i]=s[len-i-1];
				else if(s[len-i-1]=='.')s[len-i-1]=s[i];
				else flag=false;
			}
		}
		if(flag)cout<<s<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
