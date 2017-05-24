#include<bits/stdc++.h>
using namespace std;

int eggDrop(int n, int k)
{
	//n¸öµ° k²ãÂ¥ 
	vector< vector<int> > dp(n+1,vector<int>(k+1,0));
	for(int i=1;i<k+1;++i)
	{
		dp[1][i]=i;
	}
	for(int j=1;j<n+1;++j)
	{
		dp[j][1]=1;
	}
	for(int i=0;i<n+1;++i)
	{
		for(int j=0;j<k+1;++j)
		{
			cout<<dp[i][j]<<" "; 
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=2;i<n+1;++i)
	{
		for(int j=2;j<k+1;++j)
		{
			//f(floors/eggs) = max(f(floors-kth,eggs) ,f(kth-1,eggs-1))
			//m±íÕ÷×ÅÂ¥²ã 
			int res=INT_MAX;
			for(int m=1;m<=j;++m)
			{
				res=min(1+max(dp[i][j-m],dp[i-1][m-1]),res);
				
			}
			dp[i][j]=res;
		}
	}
	for(int i=0;i<n+1;++i)
	{
		for(int j=0;j<k+1;++j)
		{
			cout<<dp[i][j]<<" "; 
		}
		cout<<endl;
	}
	return 0;
} 
int main()
{
	eggDrop(2,10);
}
