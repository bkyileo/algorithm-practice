//hihocoder «¯”Ú÷‹≥§
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> maze,vector<vector<bool>> &visit,int curr,int x,int y,vector<pair<int,int>> &points)
{
	if(x<0||x>=maze.size()||y<0||y>=maze[0].size())
		return ;
	if(visit[x][y]==false && maze[x][y]==curr)
	{
		visit[x][y]=true;
		points.push_back(make_pair(x,y));
		dfs(maze,visit,curr,x+1,y,points);
		dfs(maze,visit,curr,x-1,y,points);
		dfs(maze,visit,curr,x,y+1,points);
		dfs(maze,visit,curr,x,y-1,points);
	}
}
int check(vector<vector<bool>> &visit,pair<int,int> p)
{
	int res=4;
	int x=p.first;
	int y=p.second;
	if(x-1>-1&&visit[x-1][y]==true)res--;
	if(x+1<visit.size()&&visit[x+1][y]==true)res--;
	if(y-1>-1&&visit[x][y-1]==true)res--;
	if(y+1<visit[0].size()&&visit[x][y+1]==true)res--; 
	return res;
}
int main()
{
	int n,m,x,y;cin>>n>>m>>x>>y;
	vector<vector<int>> maze(n,vector<int>(m));
	vector<vector<bool>> visit(n,vector<bool>(m,false));
	for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)
	cin>>maze[i][j];
	int curr=maze[x][y];
	//visit[x][y]=true;
	vector<pair<int,int>> points;
	dfs(maze,visit,curr,x,y,points);
	int res=0;
	for(auto i:points)
	{
		res+=check(visit,i);
	}
	cout<<res<<endl;
}
