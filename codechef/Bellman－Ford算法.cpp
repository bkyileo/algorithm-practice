//Bellman£­FordËã·¨ ×î¶ÌÂ·¾¶
#include<bits/stdc++.h>
using namespace std;
#define len_max 10000000 
struct edge
{
	int a;
	int b;
	int cost;
};
int main()
{
	int N,M;
	cin>>N>>M;
	vector<edge> edges(M);
	for(int i=0;i<M;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edges[i].a=x;
		edges[i].b=y;
		edges[i].cost=z;
	}
	for(int k=1;k<=N;k++)
	{
		vector<int> dis(N+1,len_max);
		dis[k]=0;
		for(int i=1;i<=N;++i)
		{
			//if(i==k) continue;
			for(int j=0;j<M;++j)
			{
				if(dis[edges[j].b]+edges[j].cost<dis[edges[j].a])
					dis[edges[j].a]=dis[edges[j].b]+edges[j].cost;
				if(dis[edges[j].a]+edges[j].cost<dis[edges[j].b])
					dis[edges[j].b]=dis[edges[j].a]+edges[j].cost;
			}
		}	
		for(int i=1;i<=N;++i)
		{
			cout<<dis[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
