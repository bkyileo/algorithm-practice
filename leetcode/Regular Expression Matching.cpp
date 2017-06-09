#include<bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) 
{
	/*
		isMatch("aa","a") ¡ú false
		isMatch("aa","aa") ¡ú true
		isMatch("aaa","aa") ¡ú false
		isMatch("aa", "a*") ¡ú true
		isMatch("aa", ".*") ¡ú true
		isMatch("ab", ".*") ¡ú true
		isMatch("aab", "c*a*b") ¡ú true
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
