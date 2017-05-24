#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    map<int,int> temp1;
    map<int,int> temp2;

    for(int i=0;i<s.length();++i)
    {

        if(temp1[s[i]]==0 && temp2[t[i]]==0)
        {
			temp1[s[i]]=t[i];
            temp2[t[i]]=s[i];
        }
        else if(temp1[s[i]]!=t[i] || temp2[t[i]]!=s[i])
            return false;
    }
    return true;
}
int main()
{
	cout<<isIsomorphic("ab","aa");
	return 0;
 } 
