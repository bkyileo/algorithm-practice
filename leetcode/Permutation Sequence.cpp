#include<bits/stdc++.h>
using namespace std;
set<string> st;
void dfs(vector<bool> mp,vector<int> curr)
{
	if(curr.size()==mp.size()-1)
	{
		string sg="";
		for(auto i:curr)
		{
			sg=sg+char(i+'0');
		}
		st.insert(sg);
		return ;
	}
	for(int i=1;i<mp.size();++i)
	{
		if(!mp[i])
		{
			mp[i]=true;
			curr.push_back(i);
			dfs(mp,curr);
			mp[i]=false;
			curr.pop_back();
		}
	}
}
string getPermutation2(int n, int k) {
    vector<bool> mp(n+1,false);
    vector<int> tp;
	dfs(mp,tp);
	for(auto i:st)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	set<string>::iterator it=st.begin();
	while(--k)it++;
	return *it;
}
void dfs2(string s,int curr)
{
	if(curr==s.length())
	{
		st.insert(s);
		return ;
	}
	for(int i=curr;i<s.length();++i)
	{
		swap(s[curr],s[i]);
		dfs2(s,curr+1);
		swap(s[i],s[curr]);
	}
}
string getPermutation(int n, int k)
{
	string sg="123456789";
	sg=sg.substr(0,n);
	dfs2(sg,0);
	/*
	for(auto i:st)
	{
		cout<<i<<" ";
	}
	*/
	cout<<endl;
	set<string>::iterator it=st.begin();
	while(--k)it++;
	return *it;	
}

int main()
{
	cout<<getPermutation(3,1)<<endl;
}
