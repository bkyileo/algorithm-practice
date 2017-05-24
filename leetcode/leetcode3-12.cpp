#include<bits/stdc++.h>
using namespace std;
vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void dfs(string digits,int i,vector<string>& res,string tp)
{
    if(i==digits.size()){
        if(tp.length()>0)
            res.push_back(tp);
        return ;
    }
    int ch=digits[i]-'0';
    for(int j=0;j<v[ch].size();++j)
    {
        tp+=v[ch][j];
        dfs(digits,i+1,res,tp);
        tp.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    string tp="";
    dfs(digits,0,res,tp);
    //for(auto i:res)cout<<i<<" ";cout<<endl;
    return res;
}
int main()
{
	letterCombinations("2"); 
} 
