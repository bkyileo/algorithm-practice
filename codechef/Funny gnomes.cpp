#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<set<int>> graph(501);
	int n;cin>>n;int curr;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	{
		cin>>curr;
		if(curr==1)
		graph[i].insert(j);
	}
	int m;cin>>m;
	while(m--)
	{
		int x,k;cin>>k>>x;
		map<vector<int>,int> mp;
		vector<int> s{x};
		int t=0;
		vector<vector<int>> temp;
		bool bl[501];
		while(mp.find(s)==mp.end()&&t<k)
		{
			mp[s]=t++;
			temp.push_back(s);
			memset(bl,false,sizeof(bl));
			for(auto i:s)
			for(auto j:graph[i])
				bl[j]=true;
			s.clear();
			for(int i=1;i<=n;++i)
			{
				if(bl[i])
					s.push_back(i);
			}
		}
		if(t==k)
		{
			if(s.size()==0)
			{
				cout<<0<<endl;
				cout<<-1<<endl;
			}
			else
			{
				cout<<s.size()<<endl;
				for(auto i:s)
				cout<<i<<" ";cout<<endl;
			}
		}
		else
		{
			int num=mp.size()-mp[s];
			k -= mp[s];
			k  = k%num;
			if(temp[k+mp[s]].size()==0)
			{
				cout<<0<<endl;
				cout<<-1<<endl;
			}
			else
			{
				cout<<temp[k+mp[s]].size()<<endl;
				for(auto i:temp[k+mp[s]])
				cout<<i<<" ";cout<<endl;
			}
		}
	}
	return 0;
} 
