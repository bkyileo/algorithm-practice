// SPFA算法求解最短路径 
#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int desti;
	int cost;
	edge(int a,int b):desti(a),cost(b){
	}
};

int main()
{
	int N,M,S,T;
	cin>>N>>M>>S>>T;
	vector<int> dis(N+1,1e9);
	vector<int> vis(N+1,0);
	//数组表示邻接矩阵
	vector<vector<edge>> es(N+1);
	dis[S]=0;
	for(int i=0;i<M;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		es[a].push_back(edge(b,c));
		es[b].push_back(edge(a,c));
	}
	queue<int> q;
	q.push(S);
	vis[S]=true;
	while(!q.empty())
	{
		int ft=q.front();
		q.pop();
		vis[ft]=false;
		for(int i=0;i<es[ft].size();++i)
		{
			if(dis[es[ft][i].desti]>dis[ft]+es[ft][i].cost )
			{
				dis[es[ft][i].desti]=dis[ft]+es[ft][i].cost;
				if(!vis[es[ft][i].desti])
				{
					q.push(es[ft][i].desti);
				}
			}
		}
	}
	cout<<dis[T]<<endl;
	return 0;
} 


