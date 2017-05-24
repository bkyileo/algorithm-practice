#include<bits/stdc++.h>
using namespace std;
int helper(string s)
{
	int res=0;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='1')res++;
	}
	return res;	
}
int main()
{
	int t,n;cin>>t;
	string l1,l2,l3;
	while(t--)
	{
		cin>>l1>>l2>>l3>>n;
		int res=helper(l1)+n*helper(l2)+helper(l3);
		if(res==0){cout<<0<<endl;continue;}
		bool flag=false;
		int ct=0;
		for(int i=l3.length()-1;i>=0;--i)
		{
			if(l3[i]=='0')
			{flag=true;break;}
			if(l3[i]=='1')
			ct++;
		}
		if(flag)
		{
			res-=ct;res++;cout<<res<<endl;continue;
		}
		else
		{
			res-=ct;
			flag=false;
			ct=0;
			for(int i=l2.length()-1;i>=0;--i)
			{
				if(l2[i]=='0')
				{flag=true;break;}
				if(l2[i]=='1')
				ct++;
			}
			if(flag)
			{res-=ct;res++;cout<<res<<endl;continue;}
			else
			{
				res-=ct*n;
				flag=false;
				ct=0;
				for(int i=l1.length()-1;i>=0;--i)
				{
					if(l1[i]=='0')
					{flag=true;break;}
					if(l1[i]=='1')
					ct++;
				}	
				if(flag)
				{res-=ct;res++;cout<<res<<endl;continue;}
				else 
				{cout<<1<<endl;continue;}
			}
		}
	}
}
