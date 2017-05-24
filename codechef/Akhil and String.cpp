#include<bits/stdc++.h>
using namespace std;
string solve(string temp,int &index,char newchar)
{
	for(int i=index;i<temp.length();++i)
	{
		if(temp[i]=='a')
			index++;
		else
			break;		
	}
	for(int i=index;i<temp.length()-1;++i)
	{
		if(temp[i]>temp[i+1])
		{
			temp=temp.substr(0,i)+temp.substr(i+1);
			temp=temp+newchar;
			return temp;
		}
	}
	if(temp[temp.length()-1]>newchar)
	{
		temp=temp.substr(0,temp.length()-1);
		temp=temp+newchar;
	}
	return temp;
}
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		string s;
		int len;
		cin>>s>>len;
		
		string temp=s.substr(0,len);
		int index=0;
		for(int i=len;i<s.length();++i)
		{
			temp=solve(temp,index,s[i]);
		} 
		cout<<temp<<endl;

	}
	return 0;
}



/*
		queue<char> q;
		
		string res="";
		double key=27.0;
		double value=0;
		double temp;
		int i=0;
		for(;i<len;i++)
		{
			q.push(s[i]);
			res=res+s[i];
			value=value*key+(s[i]-'a')*1.0;
		}
		temp=value;
		while(i<s.length())
		{
			char top=q.front();
			value=( value - (top-'a')*pow(key,len-1) )*27.0 + s[i]-'a';
			if(value<temp)
			{
				temp=value;
				res=res.substr(1);
				res=res+s[i];
			}
			q.pop();
			q.push(s[i]);
			i++;
		}
		cout<<res<<endl;
*/ 
 
