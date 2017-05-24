#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,string curr,int all,vector<string>& res)
{
	if(i==all&&j==all)
	{
		res.push_back(curr);
		return ;
	}
	if(i<all)dfs(i+1,j,curr+'(',all,res);
	if(j<i)dfs(i,j+1,curr+')',all,res);
}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	string tp="";
	dfs(0,0,"",n,res);
	for(auto i:res)cout<<i<<" ";cout<<endl;
	return res;    
}
int main() 
{
	generateParenthesis(3);
	return 0;
} 
