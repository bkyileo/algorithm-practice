//Shortest Palindrome 
#include<bits/stdc++.h>
using namespace std;
// c a t a c b # b c a t a c
// 0 0 0 0 1 0 0 0 1 2 3 4 5
class Solution {
public:
    string shortestPalindrome(string s) {
        int ind;
        string srev;
        srev.assign(s.rbegin(), s.rend());
        stringstream ss;
        ss << s << '#' << srev;
        ind = getTable(ss.str());
        ss.str(""); 
        srev = s.substr(ind);
        reverse(srev.begin(), srev.end());
        ss << srev << s;
        return ss.str();
    }

    int getTable(string s){
        int len = s.length();
        vector<int> table(len, 0);
        int j = 0;
        int i = 1;
        while(i<len)
        {
        	if(s[i]==s[j])
        	{
				j++;
        		table[i]=j;
				i++
			}
			else
			{
				if(j!=0)
					j=table[j-1];
				else
				{
					table[i]=0;
					i++;
				}
			}		
		}
        return table[len - 1];
    }
}; 
