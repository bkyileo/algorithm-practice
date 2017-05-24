/*
Restore IP Addresses My Submissions Question
Total Accepted: 52831 Total Submissions: 228999 Difficulty: Medium
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Subscribe to see which companies asked this question
*/ 
#include<bits/stdc++.h>
using namespace std;
void backtracing(vector<string>& R,string s,int left)
{
	cout<<s<<endl;
	if(s.find_last_of('.')==s.length()-1)
	{
		cout<<"over"<<endl;
		return;
	}
	if (left==0)
	{
		int last=atoi((s.substr(s.find_last_of('.')+1)).c_str());
		if(last>-1 && last<256 )
			{
			R.push_back(s);
			cout<<"yes"<<endl;
		}
		return ;
	}

	backtracing(R,s.insert(s.find_last_of('.')+1,"."),left-1);
	backtracing(R,s.insert(s.find_last_of('.')+2,"."),left-1);
	if (atoi(s.substr(s.find_last_of('.'),3).c_str())<=256)
	backtracing(R,s.insert(s.find_last_of('.')+3,"."),left-1);
	
}

int main()
{
	
	vector<string> res;
	backtracing(res,"25525511135",3);
	for (int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
}
