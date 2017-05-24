//code chef Cascading Style Sheets
#include<bits/stdc++.h>
using namespace std;
int main()
{
	/* 
		id attr v p
		mp1[id,attr] : v
		mp2[id,attr] : p
	*/	
	map<pair<int,int>,int> mp1;
	map<pair<int,int>,int> mp2;
	int n,m;cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		int id,attr,v,p;cin>>id>>attr>>v>>p;
		if(mp1[make_pair(id,attr)]==0)
		{
			mp1[make_pair(id,attr)]=v;
			mp2[make_pair(id,attr)]=p;
		}
		else
		{
			if(mp2[make_pair(id,attr)]<=p)
			{
				mp1[make_pair(id,attr)]=v;
				mp2[make_pair(id,attr)]=p;				
			}
		}
	}
	for(int i=0;i<m;++i)
	{
		int id,attr;cin>>id>>attr;
		cout<<mp1[make_pair(id,attr)]<<endl;
	}
	return 0;
}
