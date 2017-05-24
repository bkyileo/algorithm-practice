// spoj two ends
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int index=0;
	while(1)
	{
		int t;cin>>t;
		if(t==0)
		{
			return 0;	
		} 
		else
		{
			index++;
			vector<int>arr(t);
			vector<vector<int>>dp(t,vector<int>(t,0));
			int sum=0;
			for(int i=0;i<t;++i)
			{
				cin>>arr[i];
				dp[i][i]=arr[i];
				sum+=arr[i];
			}
			for(int i=0;i<t-1;++i)
				dp[i][i+1]=max(dp[i][i],dp[i+1][i+1]);
			for(int L=2;L<t;++L)
			{
				for(int left=0;left+L<t;++left)
				{
					//If there is a tie, remove the left end
					int right=left+L;
					int curr=0;
					if(arr[right]>arr[left+1])
						curr=max(curr,dp[left+1][right-1]+arr[left]);
					if(arr[left+1]>=arr[right])
						curr=max(curr,dp[left+2][right]+arr[left]);
					if(arr[left]>=arr[right-1])
						curr=max(curr,dp[left+1][right-1]+arr[right]);
					if(arr[right-1]>arr[left])
						curr=max(curr,dp[left][right-2]+arr[right]);
					dp[left][right]=curr;
					/*
					dp[i][j] = dp[i+1][j-1]+arr[i] if(arr[j]>=arr[i])
					dp[i][j] = dp[i+2][j]+arr[i] if(arr[i+1]>=arr[j])
					dp[i][j] = dp[i+1][j-1]+arr[j] if(arr[i]>=arr[j])
					dp[i][j] = dp[i][j-2]+arr[j] if(arr[j-1]>=arr[i])
					*/ 
				}
			}
			/*
			for(auto i:dp)
			{
				for(auto j:i)
					cout<<j<<" ";
				cout<<endl;
			}
			*/
			cout<<"In game "<<index<<", the greedy strategy might lose by as many as "<<2*dp[0][t-1]-sum<<" points."<<endl;
		}
	}
}
