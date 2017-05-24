#include<bits/stdc++.h>
using namespace std;

void find(int k,int n,vector<int> temp,vector<vector<int>> &res)
{

	if(k==0 && n==0)
	{
		for(auto i:temp)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		
		res.push_back(temp);
		return;
	}

	if(k>0 && n>0)
	{
		int localMax=0;
		for(int i=0;i<temp.size();++i)
			localMax=max(localMax,temp[i]);
		for(int i=localMax+1;i<10;++i)
		{
			temp.push_back(i);
			find(k-1,n-i,temp,res);
			temp.pop_back();
		}
	}
}

vector< vector<int> > combinationSum3(int k, int n) {
    vector< vector<int> > res;
    vector<int> temp;
    find(k,n,temp,res);
    return res;
} 

int main()
{
	combinationSum3(2,6); 
	return 0;
}
