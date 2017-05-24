#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int t;
    cin>>t;
    vector< vector<long long> > dp(2001,vector<long long>(2001,0));
    dp[1][1]=1;
    dp[2][2]=2;

    if(t<3)
    {
        int ans=0;
        for(int i=1;i<dp[0].size();++i)
            ans+=dp[t][i];
        cout<<ans<<endl;
    }
    else
    {
        for(int i=3;i<=t;++i)
        {
            for(int j=1;j<i;++j)
            {
                for(int k=1;k<20;++k)
                {
                    dp[i][k+1]+=(dp[j][k]*dp[i-1-j][k]);
                    if(dp[i][k+1]>mod)dp[i][k+1]=dp[i][k+1]%mod;
                    dp[i][k+1]+=(dp[j][k]*dp[i-1-j][k-1]);
                    if(dp[i][k+1]>mod)dp[i][k+1]=dp[i][k+1]%mod;
                    dp[i][k+2]+=(dp[j][k]*dp[i-1-j][k+1]);
                    if(dp[i][k+2]>mod)dp[i][k+2]=dp[i][k+2]%mod;
                }
            }
        }
        int ans=0;
        for(int i=1;i<dp[0].size();++i)
        {
            ans+=dp[t][i];
            ans=ans%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
