#include<bits/stdc++.h>
using namespace std;
/*
4 7
.#..... 
.##....  
....##.  
....#..
*/
struct res
{
	int a,b,c;
};
void dfs(int i,int j,vector<string> maze,vector< vector<bool> >& visit,int &square,int det,vector<int>& path,int id)
{
	//cout<<"i j :"<<i<<" "<<j<<endl;
	int n=maze.size();
	int m=maze[0].size();
	if(i<0||i>=n||j<0||j>=m||maze[i][j]=='.'||visit[i][j])
		return;
	visit[i][j]=true;
	path.push_back(det);
	path.push_back(id);
	square++;
	dfs(i+1,j,maze,visit,square,1,path,id+1);
	dfs(i-1,j,maze,visit,square,2,path,id+1);
	dfs(i,j+1,maze,visit,square,3,path,id+1);
	dfs(i,j-1,maze,visit,square,4,path,id+1);
}
res landNum(vector<string> maze)
{
	int n,m;
	n=maze.size();
	m=maze[0].size();
	vector< vector<bool> > visit(n,vector<bool>(m,false));
	res r;
	r.c=0;r.a=0;r.b=0;
	set<int> temp;
	set< vector<int> > paths;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(maze[i][j]=='#' && !visit[i][j])
			{
				int s=0; 
				vector<int> currpath;
				dfs(i,j,maze,visit,s,0,currpath,0);
				temp.insert(s);
				paths.insert(currpath);
				r.a++;
			}	
		}
	}
	r.b=temp.size();
	r.c=paths.size();
	/*
	for(auto i:paths)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	 }
	 */ 
	return r;
}
int main()
{
	
	int N,M;
	cin>>N>>M;
	vector<string> maze;
	for(int i=0;i<N;++i)
	{
		string curr;
		cin>>curr;
		maze.push_back(curr);
	}
	res out=landNum(maze);
	cout<<out.a<<" "<<out.b<<" "<<out.c<<endl;
	
	return 0;
}
