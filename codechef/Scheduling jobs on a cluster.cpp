//Scheduling jobs on a cluster
#include<bits/stdc++.h>
using namespace std;
int N,M,B,C;
long long Ns[505][505];
#define first f
#define second s
set<pair<int,int>> load;//处理时间，机器id
set<pair<int,pair<int,int>>> batch;//任务的处理时间,任务id,初始节点
set<pair<int,pair<int,int>>>::iterator point;
long long ans[510];
int main()
{
	cin>>N>>M>>B>>C;
	for(int i=1;i<=N;++i)
	for(int j=1;j<=N;++j)
	cin>>Ns[i][j];
	
	for(int i=1;i<=N;++i)load.insert(makepair(0,i));
	for(int i=0;i<M;++i)
	{
		int c=C;
		batch.clear();
		for(int j=1;j<=B;++j)
		{
			int start,currload;cin>>start>>currload;
			batch.insert(make_pair(currload,make_pair(i,start)));
		}
		for(point=batch.rbegin();point!=batch.rend();++point)
		{
	  	 	it=load.begin();
			while(c-(Ns[*point.s.s][it->s])<0)it++;
      			c-=(Ns[*point.s.s][it->s]);
      			ans[*point.s.f]=it->s;
      			pair<int,int> temp=*it;
      			load.erase(temp);
      			temp.F += v[i].F;
      			load.insert(temp);
    			for(int i=1;i<=b;i++)
     				cout<<ans[i]<<"\n";
		}
	}
	return 0;
} 
