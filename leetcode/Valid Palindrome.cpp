/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome. 
*/

#include<bits/stdc++.h>
using namespace std;
bool helper(char ch)
{
	if ((ch<='9' && ch>='0') || (ch<='z' && ch>='a') || (ch<='Z' && ch>='A'))
		return true;
	return false;
}

bool isPalindrome(string s) {
	//if (s.length()==0) return true;
	
	int first = 0;
	int end = s.length()-1;
	
	while(first<end)
	{
		//cout<<first<<" "<<end<<endl;
		//cout<<s[first]<<" "<<s[end]<<endl;
		if(!helper(s[first])) 
		{
			first++;
			continue;
		}
		if(!helper(s[end])) 
		{
			end--;
			continue;
		}
		if(s[first]==s[end] || (abs(s[first]-s[end])==('a'-'A') && s[first]>='A' && s[end]>='A' ))
		{
			first++;
			end--;
			continue;
		}
		return false;
	}
	return true;
}

int main()
{
	//cout<<helper('`')<<endl;
	cout<<isPalindrome("`l;`` 1o1 ??;l`")<<endl;
}
