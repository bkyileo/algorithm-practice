//hihocoder 二进制小数
#include<bits/stdc++.h>
using namespace std;
//模拟 减法 
string subtrac(string a,string b)
{
	int flag=0;
	string res="0.";
	int size=max(a.length(),b.length());
	if(a.length()>b.length())
	{
		int add=a.length()-b.length();
		while(add--)
		{
			b=b+'0';
		}
	}
	if(a.length()<b.length())
	{
		int add=b.length()-a.length();
		while(add--)
		{
			a=a+'0';
		}
	}
	int i=2;
	while(i<size)
	{
		if(flag==0 && b[i]>a[i]) return"-";
		if(flag==0 && b[i]==a[i]){++i;res=res+'0';continue;}
		if(flag==0 && a[i]>b[i]){flag=1;res=res+(char)('0'+a[i]-b[i]);++i;continue;}
		
		if(flag==1 && b[i]==a[i]){++i;res=res+'0';continue;}
		if(flag==1 && a[i]>b[i]){res=res+(char)('0'+a[i]-b[i]);++i;continue;}
		if(flag==1 && b[i]>a[i])
		{
			//循环借位 
			int k= res.length()-1;
			while(res[k]=='0')
			{
				k--;
			}
			res[k]=(char)(res[k]-1);
			for(int j=k+1;j<res.length();++j)
			{
				res[j]='9';
			}
			res=res+(char)('0'+a[i]-b[i]+10);
			++i;
			continue;
		}
	}
	return res;	
} 
//模拟 a*0.5
string muli(string a)
{
	string res="0.";
	int i=2;
	while(a[i]=='0') 
	{
		res+="0";
		i++;
	}
	int add=0;
	string rest="";
	for(int j=a.length()-1;j>=i;--j)
	{
		rest=(char)( (a[j]-'0')*5%10+'0'+add )+rest;
		add=(a[j]-'0')*5/10;
	}
	if(add!='0')
	{
		res=res+char(add+'0');
		res=res+rest;
	}
	else
	{
		res=res+'0';
		res=res+rest;
	}
	return res;
}

bool check(string a)
{
	int i=2;
	while(a[i]=='0'&&i<a.length())
		i++;
	if(i==a.length())
		return true;
	return false;
}
int main()
{
//	cout<<check("0.005")<<endl;
//	cout<<check("0.000000")<<endl;
//	cout<<muli("0.040563")<<endl;
//	cout<<0.040563*0.5<<endl;
//	cout<<subtrac("0.897","0.258147")<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		string target;
		cin>>target;
		string start="0.5";
		string res="0."; 
		while( !check(target)  )
		{
			if(start.length()>target.length())
			{
				res="NO";
				break;
			}	
			if(subtrac(target,start)!="-")
			{
				target=subtrac(target,start);
				res=res+'1';
				start=muli(start);
			}
			else
			{
				res=res+'0';
				start=muli(start);
			}
		}
		cout<<res<<endl;
	}
	return 0;

} 
