//codeforces One Bomb
#include<bits/stdc++.h>
using namespace std;
char maze[1005][1005];
int a[1005];
int b[1005];
int main()
{
	int n,m;cin>>n>>m;
	memset(a,0,sizeof(a));
	memset(a,0,sizeof(b));
	int count=0;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		cin>>maze[i][j];
		if(maze[i][j]=='*')
		{
			count++;
			a[i]++;
			b[j]++;
				
		}
	}
	if(count==0)
	{
		cout<<"YES"<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		if(maze[i][j]!='*' && a[i]+b[j]==count)
		{
			cout<<"YES"<<endl;
			cout<<i<<" "<<j<<endl;
			return 0;
		}
		if(maze[i][j]=='*' && a[i]+b[j]==count+1)
		{
			cout<<"YES"<<endl;
			cout<<i<<" "<<j<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;	
}
