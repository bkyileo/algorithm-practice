#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;cin>>s;
	vector<bool> table(26,false);
	for(auto i:s)table[i-'a']=true;
	int n;cin>>n;
	while(n--)
	{
		string curr;cin>>curr;
		bool flag=true;
		for(auto i:curr)if(!table[i-'a'])flag=false;
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
