// hihocoder 逃离迷宫
#include<bits/stdc++.h>
using namespace std;
int N,M,K,a,b,c,d;
//N M弄反了，学到了bfs的方法 
char maze[105][105];
bool visit[105][105][64];
int keys[105][105];
int dix[4]={1,-1,0,0};
int diy[4]={0,0,1,-1};

int main()
{
	cin>>N>>M>>K>>a>>b>>c>>d;
	memset(visit,false,sizeof(visit));
	memset(keys,0,sizeof(keys));
	for(int i=0;i<N;++i)
	for(int j=0;j<M;++j)
		cin>>maze[i][j];
	int x,y;
	for(int i=0;i<K;++i)
	{
		cin>>x>>y;
		keys[x][y] |= 1<<i;
		//keys[x][y] = 'A'+i;
	}
	queue<pair<pair<int,int>,pair<int,int>>> q;//a,b,key,step
	q.push(make_pair(make_pair(a,b),make_pair(keys[a][b],0)));
	visit[a][b][keys[a][b]]=true;
	bool flag=false;
	while(!q.empty())
	{
		pair<pair<int,int>,pair<int,int>> ft=q.front();
		q.pop();
		if(ft.first.first==c&&ft.first.second==d)
		{
			cout<<ft.second.second<<endl;
			flag=true;
			break;
		}
		else
		{
			int kys=ft.second.first;
			int step=ft.second.second;
			for(int i=0;i<4;++i)
			{
				int nx=ft.first.first+dix[i];
				int ny=ft.first.second+diy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<M)
				{
					if(maze[nx][ny]=='#')
					{
						continue;
					}
					else
					{
						if(maze[nx][ny]=='.')
						{
							if(!visit[nx][ny][kys])
							{
								visit[nx][ny][kys]=true;
								q.push(make_pair(make_pair(nx,ny),make_pair(kys|keys[nx][ny],step+1)));
								visit[nx][ny][kys|keys[nx][ny]]=true;
							}
						}
						else
						{
							if(!visit[nx][ny][kys]&&(kys>>(maze[nx][ny]-'A')&1))
							{
								visit[nx][ny][kys]=true;
								q.push(make_pair(make_pair(nx,ny),make_pair(kys|keys[nx][ny],step+1)));
								visit[nx][ny][kys|keys[nx][ny]]=true;	
							}
						}
					}
				}
			}	
		}
	}
	if(!flag)
		cout<<-1<<endl;
	return 0;

} 
