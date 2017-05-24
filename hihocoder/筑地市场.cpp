#include<bits/stdc++.h>
using namespace std;
long long k;
long long dp[22][2][2];
int n[22];
long long dfs(int x,int y1,int y2,int z)
{
    if(x==-1)return y1||y2?1:0;
    if(!z&&dp[x][y1][y2]!=-1)return dp[x][y1][y2];
    int e = z?n[x]:9;long long ans=0;
    for(int i=0;i<=e;i++)
    {
    	int temp=dfs(x-1,y1||(i==4),y2||(i==7),z&&(i==e));
		ans+=temp;
	} 
	if(!z)dp[x][y1][y2]=ans;
    return ans;
}
long long solve(long long x)
{
    int num=0;
    while(x)
    {
        n[num++]=x%10;
        x/=10;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(num-1,0,0,1);
}
int main()
{
//    scanf("%lld",&k);
//    long long l=1,r=2e18,ans=4;
//    while(l<=r)
//    {
//        long long mid = (l+r)/2;
//        if(solve(mid)>=k)r=mid-1,ans=mid;
//        else l=mid+1;
//    }
	int t;
	while(1)
	{
	cin>>t;
	memset(dp,-1,sizeof(dp));
	memset(n,-1,sizeof(n));
    cout<<solve(t)<<endl;
    for(auto i:n)
    {
    	cout<<i<<" ";
	}
	cout<<endl; 
	for(int i=0;i<2;++i)
	{
		for(int j=0;j<2;++j)
		{
			for(int k=0;k<22;k++)
				cout<<dp[k][i][j]<<" ";
			cout<<endl;
		}
	}
	}
}
