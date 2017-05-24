#include<bits/stdc++.h>
using namespace std;
/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.
Subscribe to see which companies asked this question
*/

string convertToTitle(int n) {
	if(n<=0)
		return "";
	
	string res="";
	vector<int> temp;
	while(n)
	{
		temp.push_back((n-1)%26);
		n=(n-1)/26;
	}

	map<int,char> dict;

	for(int i=0;i<26;++i)
	{
		dict[i]='A'+i;
	}
	for(int i=0;i<temp.size();++i)
	{
		res = dict[temp[i]] + res;
	}

	return res;    
}

int main()
{
	cout<<convertToTitle(26*27)<<endl;
	return 0;
}
