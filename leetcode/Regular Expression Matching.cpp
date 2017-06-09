#include<bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) 
{
	/*
		isMatch("aa","a") �� false
		isMatch("aa","aa") �� true
		isMatch("aaa","aa") �� false
		isMatch("aa", "a*") �� true
		isMatch("aa", ".*") �� true
		isMatch("ab", ".*") �� true
		isMatch("aab", "c*a*b") �� true
	*/
	if (p.empty())    return s.empty(); 
    if ('*' == p[1])
        return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p)));
		//      "abc"->"ad*bc"                             "ab"->"ab"("a.")                 "bbbb"->"b*"
    else
        return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
	
}
int main()
{
	return 0;
} 
