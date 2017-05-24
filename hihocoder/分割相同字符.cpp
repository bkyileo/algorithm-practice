//hihocoder 分隔相同字符
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> alpha,int len,int curr)
{
	alpha[curr]--;
	int temp;
	if(len%2==1) temp=len/2+1;
	else temp=len/2;
	for(int i=0;i<26;++i)
	{
		if(alpha[i]>temp)
			return false;
	}
	return true;
}

int main()
{
	string s;cin>>s;
	vector<int> alpha(26,0);
	for(int i=0;i<s.length();++i)
	{
		alpha[s[i]-'a']++;
	}
	
	int temp;
	if(s.length()%2==1) temp=s.length()/2+1;
	else temp=s.length()/2;
	for(int i=0;i<26;++i)
	{
		if(alpha[i]>temp)
		{
			cout<<"INVALID"<<endl;
			return 0;
		}
	}
	
	string res="";
	int last=-1;
	for(int i=0;i<s.length()-1;++i)
	{
		for(int j=0;j<26;++j)
		{
			if(alpha[j]>0&&j!=last&&check(alpha,s.length()-i-1,j))
			{
				res+=char(j+'a');
				last=j;
				alpha[j]--;
				//cout<<res<<endl; 
				break;
			}
		}
	}
	
	char lastone;
	for(int i=0;i<26;++i)
		if(alpha[i]>0)
			lastone=char(i+'a');
	//最后情况 
	if(res[res.length()-1]!=lastone)
	{
		cout<<res<<lastone<<endl;
		return 0;
	}
	//中间情况 
	for(int i=res.length()-1;i>0;--i)
		if(res[i]!=lastone && res[i-1]!=lastone)
		{
			res.insert(i,1,lastone);
			cout<<res<<endl;
			return 0;
		}
	//开始情况
	cout<<lastone;
	cout<<res<<endl;
	return 0;
} 
