#include<bits/stdc++.h>
using namespace std;
int func(string s);
int main()
{
	string s;cin>>s;
	cout<<func(s)<<endl;
	return 0;
}
int func(string s)
{
	/*
	5312
		2 + 12 + 312 + 5312
		1 + 31 + 531
		3 + 53 
		5
	*/
	int mod = 1e9 + 7;
	long long res = (int)(s[0]-'0');
	long long curr ;
	long long  last = (int)(s[0]-'0');
	for(int i=1;i<s.length();++i)
	{
		curr = ((last*10 % mod) + (i+1)*(int)(s[i]-'0'))%mod;
		res =  (res + curr)%mod;
		last = curr;
 	}
	return res;
} 
