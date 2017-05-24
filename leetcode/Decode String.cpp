#include<bits/stdc++.h>
using namespace std;
//不动原来的字符串，用引用带着索引走 
string helper(string s,int& i)
{
	string res="";
	while(i<s.length()&&s[i]!=']')
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			res+=s[i];
			i++;
		}
		else
		{
			int curr=0;
			while(s[i]<='9'&&s[i]>='0')
			{
				curr=curr*10+(int)(s[i]-'0');
				i++;
			}
			i++;
			string temp=helper(s,i);
			i++;
			while(curr>0)
			{
				res+=temp;
				curr--;
			}
		}
	}
	return res;
}
string decodeString(string s) {
	int i=0; 
	return helper(s,i);
}
int main()
{
	cout<<decodeString("sd2[f2[e]g]i")<<endl;
	return 0;
} 
