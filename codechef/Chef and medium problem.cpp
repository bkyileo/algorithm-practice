//Chef and medium problem
#include<bits/stdc++.h>
using namespace std;
set<int> sets[6];
set<int>::iterator it;
int main()
{
	int n;cin>>n;
	vector<int> arr(n+1);
	for(int i=1;i<=n;++i)
	{
		cin>>arr[i];
		if(arr[i]%2==0)
		sets[2].insert(i);
		if(arr[i]%3==0)
		sets[3].insert(i);
		if(arr[i]%5==0)
		sets[5].insert(i);
	}
	int q;cin>>q;
	while(q--)
	{
		int a,b,c,d;
		cin>>a;
		if(a==1)
		{
			cin>>b>>c>>d;
			it=lower_bound(sets[d].begin(),sets[d].end(),b);
			vector<int> temp;
			for(auto i=it;i!=sets[d].end();++i)
			{
				if(*i>c)break;
				else
				{
					arr[*i]/=d;
					if(arr[*i]%d)
					{
						temp.push_back(*i);
					}
				}				
			}
			for(auto i:temp)
				sets[d].erase(i);
		}
		if(a==2)
		{
			cin>>b>>c;
			sets[2].erase(b);
			sets[3].erase(b);
			sets[5].erase(b);
			arr[b]=c;
			if(arr[b]%2==0)sets[2].insert(b);
			if(arr[b]%3==0)sets[3].insert(b);
			if(arr[b]%5==0)sets[5].insert(b);
		}
	}
	for(int i=1;i<=n;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
} 
