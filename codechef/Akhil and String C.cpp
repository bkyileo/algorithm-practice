#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	//scanf("%d",&t);
	cin>>t; 
	while(t--)
	{
		int len;
		string s;
		stack<char> sk; 
		cin>>s;
		cin>>len;
		int size=s.length()-len;
		for(int i=0;i<s.length();++i)
		{
			while(!sk.empty() && sk.top()>s[i] && size>0)
			{
				size--;
				sk.pop();
			}
			sk.push(s[i]);
		}
		stack<char> res;
		while(!sk.empty())
		{
			res.push(sk.top());
			sk.pop();
		}
		for(int i=0;i<len;++i)
		//while(!res.empty())
		{
			cout<<res.top();
			res.pop();
		}
		cout<<endl;
	}
	return 0;
}
