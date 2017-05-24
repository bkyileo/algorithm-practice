#include<bits/stdc++.h>
using namespace std;
int calculateMinimumHP(vector< vector<int> >& dungeon) {
	if(dungeon.size()==0) 
		return 0;
	vector< vector<int> >dp(dungeon);
	int m=dungeon.size()-1;
	int n=dungeon[0].size()-1;
	
	dp[m][n]=dp[m][n]>0?0:dp[m][n];
	
	for(int i=m-1;i>=0;--i)
	{
		if(dp[i][n]+dp[i+1][n]>0)
			dp[i][n]=0;
		else
			dp[i][n]=dp[i][n]+dp[i+1][n];
	}
	
	for(int i=n-1;i>=0;--i)
	{
		if(dp[m][i]+dp[m][i+1]>0)
			dp[m][i]=0;
		else
			dp[m][i]=dp[m][i]+dp[m][i+1];
	}
	
	for(int i=m-1;i>=0;--i)
	{
		for(int j=n-1;j>=0;--j)
		{
			if(max(dp[i+1][j],dp[i][j+1])+dp[i][j]>0)
				dp[i][j]=0;
			else
				dp[i][j]=max(dp[i+1][j],dp[i][j+1])+dp[i][j];
				
		}
	}
	return 1-dp[0][0];
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
	
	cout<<calculateMinimumHP(puzzle);
	return 0;
}
