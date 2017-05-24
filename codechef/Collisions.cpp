#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m;cin>>n>>m;
		vector<string> maze(n);
		for(int i=0;i<n;++i)
		{
			cin>>maze[i];
		}
		int res=0;
		for(int i=0;i<maze[0].size();++i)
		{
			int temp=0;
			for(int j=0;j<maze.size();++j)
			if(maze[j][i]=='1')temp++;
			res+=temp*(temp-1)/2;
		}
		cout<<res<<endl;
	}
	return 0;
}

