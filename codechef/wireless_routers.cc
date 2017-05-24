#include<bits/stdc++.h>
#define N 1005
#define M 105
using namespace std;
int n,m;
vector<int> edge[N];
int v[N];
// dpsat[curr][used][isput][iswifi]
// son -> father (no)
// father -> son (yes)
int dp[N][M][2][2];
void init()
{
	memset(v,0,sizeof(v));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i)
	{
		dp[i][0][1][1]=-1000005;
		dp[i][0][0][1]=-1000005;
	}
}
void dfs(int curr,int past)
{
	int sons=0;
	for(int j=0;j<edge[curr].size();++j)
	{
		if(edge[curr][j]!=past) sons++;
	}
	if(sons==0)
	{
		dp[curr][1][1][1]=v[curr];
	}
	else if (sons==1)
	{	
		int son=edge[curr][0]==past?edge[curr][1]:edge[curr][0];
		dfs(son,curr);
		for(int i=0;i<=m;i++)
		{		
			dp[curr][i+1][1][1]=max(max(dp[curr][i+1][1][1],dp[son][i][1][1]+v[curr]),max(dp[son][i][0][1]+v[curr],dp[son][i][0][0]+v[curr]+v[son]));
			dp[curr][i][0][1]=max(dp[curr][i][0][1],dp[son][i][1][1]+v[curr]);         
			dp[curr][i][0][0]=max(max(dp[curr][i][0][0],dp[son][i][0][0]),dp[son][i][0][1]);
		}      
	}
	else
	{
		int son1,son2;
		if(past==edge[curr][0]){
			son1=edge[curr][1];
			son2=edge[curr][2];
		}
		else if(past==edge[curr][1])
		{
			son1=edge[curr][0];
			son2=edge[curr][2];							
		}
		else if(past==edge[curr][2])
		{
			son1=edge[curr][0];
			son2=edge[curr][1];								
		}
		dfs(son1,curr);
		dfs(son2,curr);
		for(int i=0;i<=m;i++){
		for(int j=0;j<=m-i;j++){
		//[0][0] 4 cases
		dp[curr][i+j][0][0]=max(dp[curr][i+j][0][0],
					max(dp[son1][i][0][1],dp[son1][i][0][0])+
					max(dp[son2][j][0][1],dp[son2][j][0][0]));
		//[0][1] 5 cases 
		dp[curr][i+j][0][1]=max(
					max
					(dp[curr][i+j][0][1],dp[son1][i][1][1]+dp[son2][j][1][1]+v[curr])
					,
					max
					(dp[son1][i][1][1]+max(dp[son2][j][0][1],dp[son2][j][0][0])+v[curr],
					dp[son2][j][1][1]+max(dp[son1][i][0][1],dp[son1][i][0][0])+v[curr])
					);
		//[1][1] 9 cases
		dp[curr][i+j+1][1][1]=max(
					max
					(dp[curr][i+j+1][1][1],
					dp[son1][i][1][1]+dp[son2][j][0][0]+v[curr]+v[son2])
					,
					max(
						max(
							max(
							dp[son1][i][1][1]+dp[son2][j][0][1]+v[curr],
							dp[son1][i][1][1]+dp[son2][j][1][1]+v[curr])
							,
							max(
							dp[son1][i][0][1]+dp[son2][j][0][0]+v[curr]+v[son2],
							dp[son1][i][0][1]+dp[son2][j][0][1]+v[curr]))
							,
						max(
							max(
							dp[son1][i][0][1]+dp[son2][j][1][1]+v[curr],								
							dp[son1][i][0][0]+dp[son2][j][0][0]+v[curr]+v[son1]+v[son2])
							,
							max(
							dp[son1][i][0][0]+dp[son2][j][0][1]+v[curr]+v[son1],
							dp[son1][i][0][0]+dp[son2][j][1][1]+v[curr]+v[son1]))));		
      		}
   		}  	
	}
    return ;
}
void debug()
{
	for(int i=1;i<=n;++i)
	{
		cout<<"curr : "<<i<<endl;
		for(int j=0;j<=m;++j)
		{
			cout<<"use :"<<j<<endl;
			cout<<dp[i][j][0][0]<<" "<<dp[i][j][0][1]<<" "<<dp[i][j][1][1]<<endl; 
		}
	}
}
int main()
{
    cin>>n>>m;   
    init();
    for(int i=1;i<=n;++i)
    {
        cin>>v[i];
    }
    for(int i=1;i<n;++i)
    {
        int e1,e2;
        cin>>e1>>e2;
        edge[e1].push_back(e2);
        edge[e2].push_back(e1);
    }
    //for(int i=1;i<=n;++i)cout<<v[i]<<" ";cout<<endl;
    int ans=0;
    int root;
    for(int i=1;i<=n;++i)if(edge[i].size()==1){root=i;break;}
    //cout<<"root : "<<root<<endl;
    dfs(root,-1);
    //debug();
    ans=max(max(dp[root][m][1][1],dp[root][m][0][1]),dp[root][m][0][0]);
    cout<<ans<<endl;
    return 0;
}
