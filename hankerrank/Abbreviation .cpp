#include<bits/stdc++.h>
using namespace std;
bool dp[1001][1001];
void solve()
{
	/*
		dp 
			 d a B c d
		   1 1 1 0 0 0	
		A  0 0 1 0 0 0 
		B  0 0 0 1 1 1
		C  0 0 0 0 1 1
	*/ 
	memset(dp,0,sizeof(dp));
	//for(int i=0;i<1001;++i)for(int j=0;j<1001;++j)dp[i][j]=false;
	string a,b;
	cin >> a >> b;
	int m = a.length();
	int n = b.length();
	// convert a to b
	int check = 'a'-'A';
	dp[0][0] = true;
	for(int i=0;a[i]<='z'&&a[i]>='a'&&i<m;++i)
	{
		dp[0][i+1]=true;
	}
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(a[i]==b[j]||abs(a[i]-b[j])==check)
				if(dp[j][i])
					dp[j+1][i+1]=true;
			if(a[i]<='z'&&a[i]>='a')
				if(dp[j+1][i])
					dp[j+1][i+1]=true;
		}
	}
	/*
	for(int j=0;j<=n;++j)
	{
		for(int i=0;i<=m;++i)
		{
			cout<<dp[j][i]<<" ";
		}
		cout<<endl;
	}
	*/
	if(dp[n][m])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
int main()
{
	int q;cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}
 
