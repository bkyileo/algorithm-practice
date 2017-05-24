//KMP algorithm

#include<bits/stdc++.h>
using namespace std;
vector<int> lpssearch(string par);
bool KMPsearch(string text,string par)
{
	vector<int> lps=lpssearch(par);
	int i=0;
	int j=0;
	while(i<text.length())
	{
		if(text[i]==par[j])
		{
			i++;
			j++;
		}
		if(j==par.length())
		{
			cout<<text.substr(i-j,j)<<endl; 
		}
		if(i<text.length() && par[j]!=text[i])
		{
			if(j!=0)
				j=lps[j-1];
			else
			{
				i++;
			}
		}
	}
	return true;
}
vector<int> lpssearch(string par)
{
	vector<int> res(par.length(),0);
	int j=0;
	int i=1;
	while(i<par.length())
	{
		if(par[i]==par[j])
		{
			//顺序 本次给lps i赋值 
			j++;
			res[i]=j;
			i++;
		}
		else
		{
			if(j!=0)
				j=res[j-1];
			else
			{
				i++;
				res[i]=0;
			}
		}
	}
	//for(auto i:res) cout<<i<<" ";cout<<endl;
	return res;
}

int main()
{
	vector<int> t=lpssearch("abcdeabcdeabcdeabcde");
	for(int i=0;i<t.size();++i)
	{
		cout<<t[i]<<" ";
	}
	//cout<<KMPsearch("ABABDABACDABABCABAB","ABABCABAB")<<endl;
	return 0;
}
