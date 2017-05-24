// code chef Chef and Time Machine
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int cases;cin>>cases;
	while(cases--)
	{
		int t,n,m;cin>>t>>n>>m;
		vector<int> days(t);
		for(int i=0;i<t;++i)
		{
			cin>>days[i];
		}
		for(int i=0;i<t;++i)
		{
			int diff;cin>>diff;
			days[i] -= diff;
		}
		vector<int> buttons(n+m);
		for(int i=0;i<n+m;++i)
		{
			cin>>buttons[i];
		}
		sort(days.begin(),days.end());
		sort(buttons.begin(),buttons.end());
		int res=0;
		int i=t-1;int j=n+m-1;
		//for(auto i:days)cout<<i<<" ";cout<<endl;
		//for(auto i:buttons)cout<<i<<" ";cout<<endl;
		while(i>-1&&j>-1)
		{
			if(buttons[j]>days[i])
			{
				j--;
				continue;	
			}
			if(buttons[j]<=days[i])
			{
				res = res+(days[i]-buttons[j]);
				j--;
				i--;
			}
		}
		while(i>-1)
		{
			res+=days[i];
			i--;
		}
		cout<<res<<endl;
	}
}
 
