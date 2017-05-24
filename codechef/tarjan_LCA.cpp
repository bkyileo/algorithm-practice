#include<bits/stdc++.h>
using namespace std;
#define N 100005
// Tarjan 塔尔杨离线算法计算 LCA 问题 
// N<=10^5，M<=10^5

/*
测试数据 
4
a b
a c
c d
c e
3
b d
e d
e c
*/


//树的存储结构 query的存储结构 
vector<int> tree[N];
vector<int> query[N];

//人物映射管理 
int rootsMask[N];
vector<int> roots;
map<string,int> mp;
int peopleId=1;

//并差集 相关操作 
int father[N];
int rnk[N];

int ancestor[N];
bool visit[N];

void makeset()
{
	for(int i=0;i<N;++i)
	{
		ancestor[i]=i; 
		father[i]=i;
		rnk[i]=0;
		visit[i]=false;
	}	
}
int search(int t)
{
	if(father[t]==t)return father[t];
	else
	{
		father[t]=search(father[t]);
		return father[t];
	} 
} 
void unionSet(int x,int y)
{
	int a=search(x);
	int b=search(y);
	if(a==b) return ;
	if (rnk[a] > rnk[b]) father[b] = a;
	else 
	{
		father[a]  = b;
		rnk[b] += rnk[a] == rnk[b];
	}
}
void dfs(int i)
{
	for(int j=0;j<tree[i].size();++j)
	{
		dfs(tree[i][j]);
		unionSet(i,tree[i][j]);
		ancestor[search(i)] = i;
	}
	visit[i]=true;
	for (int j = 0; j < query[i].size(); j++) 
		if (visit[query[i][j]]) 
			printf("%d和%d的最近公共祖先为：%d\n", i, 
					query[i][j], ancestor[search(query[i][j])]);
	
}

void whatis()
{
	cout<<"map"<<endl;
	for(auto i:mp)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
	cout<<"roots "<<endl;
	for(int i=0;i<roots.size();++i)
	{
		cout<<roots[i]<<" ";
	}
	cout<<endl;
	cout<<"people"<<endl;
	for(int i=1;i<peopleId;++i)
	{
		cout<<i<<" ";
		for(auto j:tree[i])
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n,m;
	cin>>n;
	memset(rootsMask,0,sizeof(rootsMask));
	while(n--)
	{
		string name1,name2;
		cin>>name1>>name2;
		if(mp[name1]==0)
			mp[name1]=peopleId++;
		if(mp[name2]==0)
			mp[name2]=peopleId++;
		tree[mp[name1]].push_back(mp[name2]);	
		rootsMask[mp[name2]]++;
	}
	
	for(int i=1;i<peopleId;++i)
	{
		if(rootsMask[i]==0)
			roots.push_back(i);
	}
	makeset();
	whatis();
	cin>>m;
	while(m--)
	{
		string name1,name2;
		cin>>name1>>name2;
		if(name1==name2)continue;
		query[mp[name1]].push_back(mp[name2]);
		query[mp[name2]].push_back(mp[name1]);
	}
	for(auto i:query)
	{
		if(i.size()>0)
		{
			for(auto j:i)
				cout<<j<<" ";
			cout<<endl;
		}
	}
	for(int i=0;i<roots.size();++i)
	{
		dfs(roots[i]);
	}
	
}
