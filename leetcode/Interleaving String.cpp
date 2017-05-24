/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	vector< vector<bool> > puzzle (s1.length()+1,vector<bool>(s2.length()+1,false));
	
	puzzle[0][0]=true;
	
	for(int i=0;i<s1.length()+1;++i)
		for(int j=0;j<s2.length()+1;++j)
		{
		 if(i>0 && puzzle[i-1][j]==true && s1[i-1]==s3[i+j-1])
		 	puzzle[i][j] = true;
		 if(j>0 && puzzle[i][j-1]==true && s2[j-1]==s3[i+j-1])
		 	puzzle[i][j] = true;
		}
			
			
	for(int i=0;i<s1.length()+1;++i)
		{
			for(int j=0;j<s2.length()+1;++j)
				cout<<puzzle[i][j]<<" ";
			cout<<endl;
		}
	
	return true;
}

int main()
{
	isInterleave("aabcc","dbbca","aadbbbaccc");
}
