//Cutting Cake
#include<bits/stdc++.h>
using namespace std;
bitset<1505> btst[1505];
int maze[1505][1505];
string ipt;
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
        cin>>ipt;
        for(int j=0;j<m;++j)
        {
            maze[i+1][j+1]=ipt[j]-'0';
        }
	}
	/*
	for(int i=1;i<n;++i)
	maze[i][0]^=maze[i-1][0];
	for(int i=1;i<m;++i)
	maze[0][m]^=maze[0][m-1];
	*/
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
        maze[i][j]^=maze[i-1][j-1];
        maze[i][j]^=maze[i-1][j];
        maze[i][j]^=maze[i][j-1];
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		btst[i][j]=maze[i][j];
	}
	long long sol=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int c= ( btst[i] ^ btst[j]).count();
			int d= m+1-c;
			sol += c*1ll*(c-1)/2;
			sol += d*1ll*(d-1)/2;
		}
	}
	cout<<sol<<endl;
}
