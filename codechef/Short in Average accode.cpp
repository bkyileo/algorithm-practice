#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		vector< pair<int,float> > edge[501];
		int n,m,from,to;float cost;cin>>n>>m;
		for(int i=0;i<m;++i)
		{
			cin>>from>>to>>cost;
			edge[from].push_back(make_pair(to,cost));
		}
		int s,e;cin>>s>>e;
		pair<int,float> dis[501];
		for(int i=0;i<501;++i)
		{
			dis[i].first=1;
			dis[i].second=100000000.0;
		}
		dis[s].second=0.1;queue<int> q;q.push(s);int step=0;
		int curr;
		int c=10000;
		bool visit[501];
		// 初始点不好处理 
		memset(visit,false,sizeof(visit));
		while(!q.empty()&&c)
		{
			queue<int> ot;
			while(!q.empty())
			{
				curr=q.front();
				visit[curr]=true;
				q.pop();
				for(int i=0;i<edge[curr].size();++i)
				{
					//cout<<"debug : "<<dis[edge[curr][i].first].second/dis[edge[curr][i].first].first<<" "<<(dis[curr].second+edge[curr][i].second)/(step+1)<<endl;
					if( dis[edge[curr][i].first].second/dis[edge[curr][i].first].first > (dis[curr].second+edge[curr][i].second)/(step+1))
					{
						dis[edge[curr][i].first].first=step+1;
						dis[edge[curr][i].first].second=dis[curr].second+edge[curr][i].second;
						//cout<<"debug 2: "<<dis[edge[curr][i].first].second<<endl;
						ot.push(edge[curr][i].first);
					}
				}
			}
			q=ot;
			step++;
			c--;
		}
		if(visit[e]==false)
			cout<<-1<<endl;
		else
			cout<<dis[e].second/dis[e].first<<endl;
		
	}
	return 0;
}
 
