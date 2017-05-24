#include<bits/stdc++.h>
using namespace std;
//πÈ≤¢≈≈–Ú
class solution
{
	static bool com(pair<int,int> a,pair<int,int> b)
	{
		return a.second>b.second;
	}
	public : void solve()
	{
		int curr,from,to,j1,j2;
		int n;cin>>n;
		vector<pair<int,int>> arr(n+1);
		for(int i=1;i<=n;++i)
		{
			cin>>curr;
			arr[i]=make_pair(i,curr);
		}
		vector<vector<pair<int,int>>> e(n+1);
		for(int i=1;i<n;++i){
			cin>>from>>to;
			e[from].push_back( arr[to] );
			e[to].push_back( arr[from] );
			e[i].push_back( arr[i] );
		}
		e[n].push_back(arr[n]); 
		sort(arr.begin()+1,arr.begin()+arr.size(), com);
		for(int i=1;i<=n;++i)
		{
			sort(e[i].begin(),e[i].begin()+e[i].size(), com);
		}
		/*
		for(int i=1;i<=n;++i)cout<<arr[i].first<<"~"<<arr[i].second<<" ";cout<<endl;
		for(int i=1;i<=n;++i)
		{
			for(auto j:e[i])
				cout<<j.first<<"~"<<j.second<<" ";
			cout<<endl;
		}
		*/
		vector<int> res(n+1,0);
		for(int i=1;i<=n;++i)
		{
			j1=1;j2=0;
			while(1)
			{
				if(j2==e[i].size())
				{
					if(j1==arr.size())
					{
						res[i]=0;
					}
					else
					{
						res[i]=arr[j1].first;
					}
					break;
				} 
				if(arr[j1].first!=e[i][j2].first)
				{
					res[i]=arr[j1].first;
					break;
				}
				if(arr[j1].first==e[i][j2].first)
				{
					j1++;j2++;
				}
			}
		}
		for(int i=1;i<=n;++i)cout<<res[i]<<" ";
		cout<<endl;
	}		
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solution s;
		s.solve();
	}	
}
/*
1
6
5 10 15 20 25 30
1 3
2 3
3 4
4 5
4 6
*/


