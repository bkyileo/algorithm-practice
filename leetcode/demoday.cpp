#include<bits/stdc++.h>
using namespace std;
struct node
{
	int right;
	int down;
	node(int x,int y):right(x),down(y){
	}
};

int main()
{
	int N,M;
	while(cin>>N>>M){	
	vector< string > maze;
	vector< vector<node> >dp(N,vector<node>(M,node(0,0)));
		
	while(N--)
	{
		string line;
		cin>>line;
		line += 'b';
		maze.push_back(line); 
	}
	string line(maze[0].size(),'b');
	maze.push_back(line);

    dp[0][0].right = maze[0][0] == 'b';
    dp[0][0].down = dp[0][0].right + (1 < dp[0].size() && maze[0][1] != 'b');

//	for (int i = 1; i < dp.size(); ++i) {
//        dp[i][0].down = min(dp[i-1][0].right + (1 < dp.size() && maze[i-1][1] != 'b'), dp[i-1][0].down) + (maze[i][0] == 'b');
//        dp[i][0].right = dp[i][0].down + (i+1 < dp[0].size() && maze[i+1][0] != 'b');
//    }
//    for (int i = 1; i < dp[0].size(); ++i) {
//        dp[0][i].right = min(dp[0][i-1].down + (1 < dp[0].size() && maze[1][i-1] != 'b'), dp[0][i-1].right) + (maze[0][i] == 'b');
//        dp[0][i].down = dp[0][i].right + (i+1 < dp[0].size() && maze[0][i+1] != 'b');
//    }	
	for(int i=1;i<dp.size();++i)
	{
		int count=0;
		for(int j=0;j<=i;++j) 
		{
			if(maze[j][0]=='b')	count++;
		}
		if(i+1!=dp.size() && maze[i+1][0]=='.')
		{
			count++;
		}
		if(dp[0][0].down==1)
		{
			count++;
		}
		dp[i][0].right = count;
	}

	for(int i=1;i<dp[0].size();++i)
	{
		int count=0;
		for(int j=0;j<=i;++j)
		{
			if(maze[0][j]=='b') count++;
		}
		if(i+1!=dp.size() && maze[0][i+1]=='.')
		{
			count++;
		}
		dp[0][i].down = count;	
	}
	
	int res;
	if(dp.size()==1)
	{ 
		cout<<dp[0][dp[0].size()-1].down<<endl;
		//return 0;
	}
	if(dp[0].size()==1) 
	{
		cout<<dp[dp.size()-1][0].right<<endl;
		//return 0;
	}
	for(int i=1;i<dp.size();++i)
	{
		for(int j=1;j<dp[0].size();++j)
		{
			dp[i][j].right = (maze[i][j]=='b')+min(dp[i][j-1].right,dp[i-1][j].down+(maze[i+1][j]=='.'));
			dp[i][j].down = (maze[i][j]=='b')+min(dp[i-1][j].down,dp[i][j-1].right+(maze[i][j+1]=='.'));
		}
	}
	res=min(dp[dp.size()-1][dp[0].size()-1].right,dp[dp.size()-1][dp[0].size()-1].down);

//	for(int i=0;i<maze.size();i++)
//	{
//		for(int j=0;j<maze[0].size();++j)
//		{
//			cout<<maze[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	for(int i=0;i<dp.size();i++)
//	{
//		for(int j=0;j<dp[0].size();++j)
//		{
//			cout<<dp[i][j].right<<"~"<<dp[i][j].down<<" ";
//		}
//		cout<<endl;
//	}
	cout<<res<<endl;
	}
	return 0;
	
 } 
 
 
