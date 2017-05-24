#include<bits/stdc++.h>
using namespace std;
bool com(string a,string b)
{
    return a.length()>b.length();
}
bool ok(string a,string b)
{
    vector<bool> visit(26,false);
    for(auto i:a)
    {
        visit[i-'a']=true;
    }
    for(auto i:b)
    {
        if(visit[i-'a'])return false;
    }
    return true;
}
int maxProduct(vector<string>& words) {
    sort(words.begin(),words.end(),com);
    int j;
    j=words.size()-1;
    int res=0;
    for(int i=0;i<j;++i)
    {
        for(int k=i+1;k<=j;++k)
        {
            if(ok(words[i],words[k]))
            {
                res=max(res,(int)words[i].length()*(int)words[k].length() );
                j=k;
                break;
            }
        }
    }
    return res;
}
int main()
{
	vector<string> arr={"abcw","baz","foo","bar","xtfn","abcdef"};
	cout<<maxProduct(arr)<<endl;
	return 0;
}
