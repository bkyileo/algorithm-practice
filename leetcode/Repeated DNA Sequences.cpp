#include<bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    map<string,int> temp;
    if(s.length()<10) return res;
    for(int i=0;i<=s.length()-10;++i)
    {
        temp[s.substr(i,10)]++;
        cout<<s.substr(i,10)<<endl;
        cout<<temp[s.substr(i,10)]<<endl;
        if(temp[s.substr(i,10)]==2)
        res.push_back(s.substr(i,10));
    }
    return res;
}

int main()
{
	vector<string> res=	findRepeatedDnaSequences("AAAAAAAAAAA");
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	 } 
} 
