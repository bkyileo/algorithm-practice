#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	int n,m;
	while(t--)
	{
		cin>>n;
		m=n/8;
		n=n%8;
		string res="";
		if(n==1||n==4)
		{
			res=to_string((8*m+(5-n)))+"LB";
		}
		if(n==2||n==5)
		{
			res=to_string((8*m+(7-n)))+"MB";
		}	
		if(n==3||n==6)
		{
			res=to_string((8*m+(9-n)))+"UB";
		}	
		if(n==7)
		{
			res=to_string(8*m+8)+"SU";
		}
		if(n==0)
		{
			res=to_string(8*m-1)+"SL";
		}
		cout<<res<<endl;	
	}
	return 0;
} 
