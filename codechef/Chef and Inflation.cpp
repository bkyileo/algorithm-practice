#include<bits/stdc++.h>
using namespace std;

int main()
{
    //陷阱1
    long long d;
    int n,m;
    cin>>n>>m>>d;
    vector< vector<int> >buy(n,vector<int>(m,0));
    vector< vector<int> >sell(n,vector<int>(m,0));
    for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
    {
        int currbuy,currsell;
        cin>>currsell>>currbuy;
        buy[i][j]=currbuy;
        sell[i][j]=currsell;
    }
    // time,station,currency m time ,n station ,2currency 1:Peppercorn 0: Antarctican Dollar
    vector< vector < vector<double> > > dp(m+1,vector< vector<double> >(n,vector<double>(2,0)));
    // step1 constructor
    for(int i=0;i<n;++i)
    {
        dp[0][i][1]=d;
    }
    //step2 cal
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<n;++j)
        {
            // d p[i][j][k] 由以下状态组成
            // 本地交易 2 在时间允许的情况下进行的交易
            dp[i][j][0]=dp[i-1][j][0];
            dp[i][j][1]=dp[i-1][j][1];
            for(int dis=1;dis<=1;++dis)
            {
                if(j-dis>=0)
                {
                    //封装兑换算法 (k-j为距离)
                    dp[i][j][0]=max(dp[i][j][0],dp[i-dis][j-dis][0]);
                    dp[i][j][1]=max(dp[i][j][1],dp[i-dis][j-dis][1]);

                }
                if(j+dis<n)
                {
                    dp[i][j][0]=max(dp[i][j][0],dp[i-dis][j+dis][0]);
                    dp[i][j][1]=max(dp[i][j][1],dp[i-dis][j+dis][1]);

                }
            }
            dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][1]/sell[j][i-1]);
            dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][0]*buy[j][i-1]);

        }
    }
    double ans=0;
    for(int i=0;i<n;++i)
    {
        ans=max(ans,dp[m][i][1]);
    }
    if (ans > 1e18)
        printf("Quintillionnaire");
    else
        //陷阱2
        printf("%.10lf\n", ans);
        //cout<<ans<<endl;
    return 0;

}
