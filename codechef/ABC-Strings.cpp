//code chef ABC-Strings
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	map<pair<long long,long long>,long long> mp;
	mp[make_pair(0,0)]=1;
	long long as=0,bs=0,cs=0;
	long long res=0;
	for(int i=0;i<s.length();++i)
	{
		as+=s[i]=='A';
		bs+=s[i]=='B';
		cs+=s[i]=='C';
		res+=mp[make_pair(as-bs,as-cs)]++;
	}
	cout<<res<<endl;
	return 0;
}
 
