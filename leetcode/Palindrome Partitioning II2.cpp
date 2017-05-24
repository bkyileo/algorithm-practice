#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s)
{
	for (int i=0;i<s.length()/2;++i)
	{
		if(s[i]!=s[s.length()-i-1])
			return false;
	}
	return true;
}

int minCut(string s) {
	vector< vector<int> > dps;
	vector<int> first(s.length(),0);
	dps.push_back(first);
	
	for(int i=1;i<s.length();++i)
	{
		vector<int> dp;
//		cout<<"第"<<i+1<<"层"<<endl;
		for(int j=0;j<s.length()-i;++j)
		{
//			cout<<"待处理"<<s.substr(j,i+1)<<endl;
			if(palindrome(s.substr(j,i+1)))
				{
//					cout<<"回文"<<endl; 
					dp.push_back(0);
				}
			else
				{
					int res=INT_MAX;
					for(int k=0;k<i;++k)
					{
//						cout<<"dps[i-k-1][j],dps[k][i-k]:"<<dps[i-k-1][j]<<" "<<dps[k][i-k]<<endl;
						res=min(res,dps[i-k-1][j]+dps[k][i-k]+1);
					}
					dp.push_back(res);
				}
		}
		dps.push_back(dp);
	}
	for(int i=0;i<dps.size();++i)
	{
		for(int j=0;j<dps[i].size();++j)
		{
			cout<<dps[i][j]<<" ";
		}
		cout<<endl;
	} 
	return dps[s.length()-1][0];
	        
}
int main()
{
	cout<<minCut("ababbbabbababa");
	return 0;
}
