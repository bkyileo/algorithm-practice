//codechef Chef And Coloring
#include<bits/stdc++.h>
using namespace std;

int solve(string s,int n)
{
	map<char,int> m;
	for(auto i:s)
	{
		m[i]++;
	}
	int countmax=m['G'];
	countmax=max(countmax,m['R']);
	countmax=max(countmax,m['B']);
	return n-countmax;
}

int main()
{
	int t;
	cin>>t;
	string s;
	int n;
	while(t--)
	{
		cin>>n>>s;
		cout<<solve(s,n)<<endl;
	}
}
