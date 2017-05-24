#include<bits/stdc++.h>
using namespace std;

struct state{
	int curr;
	int health;
	state(int x,int y):curr(x),health(y){
	}
};

int calculateMinimumHP(vector< vector<int> >& dungeon) {
	if(dungeon.size()==0) 
		return 0;
    vector< vector<state> > dp(dungeon.size(),vector<state>(dungeon[0].size(),state(0,0)));
	dp[0][0].curr=dungeon[0][0]>0?dungeon[0][0]:1;
	dp[0][0].health=dungeon[0][0]>0?0:1-dungeon[0][0];
	
	for(int i=1;i<dp.size();++i)
	{
		dp[i][0].curr=dp[i-1][0].curr+dungeon[i][0]>0?dp[i-1][0].curr+dungeon[i][0]:1;
		dp[i][0].health=dp[i-1][0].curr+dungeon[i][0]>0?dp[i-1][0].health:dp[i-1][0].health-(dp[i-1][0].curr+dungeon[i][0])+1;
	}

	for(int i=1;i<dp[0].size();++i)
	{
		dp[0][i].curr=dp[0][i-1].curr+dungeon[0][i]>0?dp[0][i-1].curr+dungeon[0][i]:1;
		dp[0][i].health=dp[0][i-1].curr+dungeon[0][i]>0?dp[0][i-1].health:dp[0][i-1].health-(dp[0][i-1].curr+dungeon[0][i])+1;
	}
	
	for(int i=0;i<dp.size();++i)
	{
		for(int j=0;j<dp[0].size();++j)
		{
			cout<<dp[i][j].curr<<"-"<<dp[i][j].health<<" ";
		}
		cout<<endl;
	}
} 

int main()
{
	int a[3]={-2,-3,3};
	int b[3]={-5,-10,1};
	int c[3]={10,30,-5};
	
	vector< vector<int> > puzzle;
	puzzle.push_back(vector<int>(a,a+3));
	puzzle.push_back(vector<int>(b,b+3));
	puzzle.push_back(vector<int>(c,c+3));
	
	calculateMinimumHP(puzzle);
	return 0;
}
