#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vector<int> players(n,0);
		int all,curr;
		int index;
		int maxs=-1;		
		for(int i=0;i<n;++i)
		{		
			cin>>all;
			players[i]+=all;
			vector<int> arr(6,0);
			for(int j=0;j<all;++j)
			{
				cin>>curr;curr--;
				arr[curr]++;
			}
			sort(arr.begin(),arr.end());
			players[i]+=arr[0]*4;
			arr[1]-=arr[0];
			arr[2]-=arr[0];
			players[i]+=arr[1]*2;
			arr[2]-=arr[1];
			players[i]+=arr[2];

			if(players[i]>maxs)
			{maxs=players[i];index=i+1;}
		}
		bool flag=false;
		for(int i=0;i<players.size();++i)
		{
			if(players[i]==maxs&&index!=i+1)flag=true;
		}
		if(flag)cout<<"tie"<<endl;
		else if(index==1)cout<<"chef"<<endl;
		else cout<<index<<endl;
	}
	return 0;
}
/*
3
2
6 1 2 3 4 5 6
9 3 3 3 4 4 4 5 5 5
2
5 2 3 4 5 6
7 1 1 2 2 3 3 4
3
4 1 1 2 3
4 1 2 2 3
4 1 2 3 3
*/
