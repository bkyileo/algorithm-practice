//code chef Chef and Robots Competition
#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> maze)
{
	//subtask1
	int n=maze.size();
	int m=maze[0].size();
	int dirx[4]={0,0,1,-1};
	int diry[4]={1,-1,0,0};
	vector<vector<bool>> visit(n,vector<bool>(m));
	queue<pair<pair<int,int>,int>> q;
	q.push(make_pair(make_pair(0,0),0));
	visit[0][0]==true;
	pair<pair<int,int>,int> curr;
	int x,y;
	while(!q.empty())
	{
		curr=q.front();
		q.pop();
		if(curr.first.first==0&&curr.first.second==m-1)
		{
			cout<<(curr.second+1)/2<<endl;
			return ;	
		}
		for(int i=0;i<4;++i)
		{
			x=curr.first.first+dirx[i];
			y=curr.first.second+diry[i];
			if(x>=0&&y>=0&&x<n&&y<m)
			{
				if(!visit[x][y]&&maze[x][y]==0)
				{
					q.push(make_pair(make_pair(x,y),curr.second+1));
					visit[x][y]=true;
				}
			}
		} 
	}
	cout<<-1<<endl;
	return ;
}


void solve2(vector<vector<int>> maze,int k1,int k2)
{
	int n=maze.size();
	int m=maze[0].size();
	cout<<n<<" "<<m<<endl;
	if(m==1)
	{
		cout<<0<<endl;
		return ;
	}
	vector<vector<int>> visit(n,vector<int>(m,0));
	queue<pair< pair<int,int>, pair<int,int>>> q;
	q.push(make_pair(make_pair(0,0),make_pair(1,0)));
	q.push(make_pair(make_pair(0,m-1),make_pair(2,0)));
	visit[0][0]=1;
	visit[0][m-1]=2;
	pair<pair<int,int>,pair<int,int>> curr;
	int x,y,go;
	while(!q.empty())
	{
		curr=q.front();
		//cout<<curr.first.first<<" "<<curr.first.second<<endl;
		q.pop();
		go=curr.second.first==1?k1:k2;
		for(int i=-go;i<=go;++i)
		for(int j=-go;j<=go;++j)
		{
			if(abs(i)+abs(j)<=go)
			{
				x=curr.first.first+i;
				y=curr.first.second+j;
				if(x>=0&&y>=0&&x<n&&y<m)
				{
					if(visit[x][y]>0&&visit[x][y]!=curr.second.first)
					{
						cout<<curr.second.second+1<<endl;
						return ;
					}
					else if(visit[x][y]==0&&maze[x][y]==0)
					{
						q.push(make_pair(make_pair(x,y),make_pair(curr.second.first,curr.second.second+1)));
						visit[x][y]=curr.second.first==1?1:2;
					}
				}
			}
		} 
	}
	cout<<-1<<endl;
	return ;
	
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m,k1,k2;
		cin>>n>>m>>k1>>k2;
		vector<vector<int>> maze(n,vector<int>(m));
		for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		cin>>maze[i][j];
		solve2(maze,k1,k2);
	}
	return 0;
}
