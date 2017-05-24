#include<bits/stdc++.h>
using namespace std;
vector<int> g;
vector<int> sk;
vector<vector<int>> table;
bool backtrace(int index)
{	
	if(index==sk.size())return true;
	for(int i=0;i<g.size();++i)
	{
		if(g[i]>-1 && table[i][g[i]]==sk[index])
		{
			g[i]--;
			if(backtrace(index+1))
				return true;
			g[i]++;		
		}
	}
	return false;
}


int main()
{
	int t;cin>>t;
	while(t--)
	{
		g.clear();
		sk.clear();
		table.clear();
		int ts;cin>>ts;
		int nums;
		if(ts==1)
		{
			stack<int> s;
			cin>>nums;
			for(int i=0;i<nums;++i){int curr;cin>>curr;s.push(curr);}
			sk=vector<int>(nums);
			for(int i=0;i<nums;++i)cin>>sk[i];
			bool flag=true;					
			for(int i=0;i<nums;++i)
			{
				if(s.top()!=sk[i])
				{flag=false;break;}
				s.pop();
			}
			if(flag)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else
		{
			table=vector<vector<int>>(ts);
		
			int all=0;
			g=vector<int>(ts);
			for(int i=0;i<ts;++i)
			{
				cin>>nums;
				all+=nums;
				g[i]=nums-1;
				vector<int> curr(nums);
				for(int j=0;j<nums;++j){cin>>curr[j];}
				table[i]=curr;
			}
			sk=vector<int>(all);
			for(int i=0;i<all;++i)cin>>sk[i];
		
			if(backtrace(0))
			cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
