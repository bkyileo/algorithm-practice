//hihocoder Dice Possibility
#include<bits/stdc++.h>
using namespace std;
double dp[101][601];
void dfs(int n,int m,double& res)
{
	if(n==0&&m==0)res++;
	if(n<0)return ;
	if(m<0)return ;
	if(6*n<m||m<n)return ;
	for(int i=1;i<7;++i)
	{
		dfs(n-1,m-i,res);
	}
}
void init()
{
	memset(dp,0,sizeof(dp));
	//dp[1][1]=1;dp[1][2]=1;dp[1][3]=1;dp[1][4]=1;dp[1][5]=1;dp[1][6]=1;
	dp[0][0]=1.0;
	for(int i=1;i<=100;++i)
	{
		for(int j=1;j<=6;++j)
		{
			for(int k=1;k<=600;++k)
			{
				if(k-j>=0)dp[i][k]+=dp[i-1][k-j];
			}
		}
	}
}
int main()
{
	init();
	int n,m;
	scanf("%d%d",&n,&m);
	//dfs Ì«Âý 
	double all=pow(6,n);
	printf("%.2f",dp[n][m]/all*100.0);
	return 0;
} 
