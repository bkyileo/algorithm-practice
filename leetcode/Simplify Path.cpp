#include<bits/stdc++.h>
using namespace std; 
string simplifyPath(string path) {
    string res,temp;
    stringstream  ss(path);
    vector<string> ch;
    while(getline(ss,temp,'/'))
    {
    	if(temp=="."||temp="")continue;
    	if(temp!="..")ch.push_back(temp);
    	if(temp==".."&&ch.size()>0)ch.pop_back();
	}
	for(auto i:ch)res+='/'+i;
	return res.length()>0?res:res;
}
int main()
{
	return 0;
}
