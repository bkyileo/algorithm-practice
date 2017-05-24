#include<bits/stdc++.h>
using namespace std;

vector<int> lps(string s)
{
    vector<int> res(s.length(),0);
    int i=1;
    int j=0;
    while(i<s.length())
    {
        if(s[i]==s[j])
        {
            j++;
            res[i]=j;
            //cout<<j<<" "<<res[j-1]+1<<endl;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=res[j-1];
            }
            else
            {
                res[i]=0;                
                i++;
            }
        }
        
    }
    return res;
}

int KMPsearch(string text,string par)
{
    vector<int> next=lps(par);
    
    for(auto i:par)
    {
    	cout<<i<<" ";
	}
	cout<<endl;  
	 
    for(auto i:next)
    {
    	cout<<i<<" ";
	}
	cout<<endl;
//  
//    for(auto i:text)
//    {
//    	cout<<i<<" ";
//	}
//	cout<<endl;
	    
	int count=0;
    int i=0;
    int j=0;
    while(i<text.length())
    {
        if(text[i]==par[j])
        {
            i++;
            j++;
        }
        if(j==par.length())
        {
            count++;
            j=next[j-1];
        }
        if(i<text.length() && text[i]!=par[j])
        {
            if(j!=0)
            {
                j=next[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return count;
}

int main()
{
    int nums;
    cout<<KMPsearch("BABABABABABABABB","BABABB")<<endl;
//    cin>>nums;
//    string text;
//    string par;
//    while(nums--)
//    {
//        cin>>par;
//        cin>>text;
//        cout<<KMPsearch(text,par)<<endl;
//    }
    return 0;
}

