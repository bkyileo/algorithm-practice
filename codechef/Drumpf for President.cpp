// code chef Drumpf for President
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int res=0;
		vector<int> arr(n+1,0);
		for(int i=1;i<=n;++i)
		{
			int curr;cin>>curr;
			if(i!=curr)
			{
				arr[curr]++;
			}
			else
			{
				arr[curr]=-1000;	
			} 
		}
		for(auto i:arr)
		if(i>=k)res++;
		cout<<res<<endl;
	}
	return 0;
} 
