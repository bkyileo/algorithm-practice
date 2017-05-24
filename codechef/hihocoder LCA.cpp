//hiho coder 最长公共祖先 dfs+rmq 
#include<bits/stdc++.h>
using namespace std;
//N<=10^5，M<=10^5
#define N 200005
vector<int> edge[N];
map <string,int> mp;
int id=1;
string peoples[N];

void input()
{
	int m;
	cin>>m;
	while(m--)
	{
		string father,son;
		cin>>father>>son;
		if(mp[father]==0)
		{
			peoples[id]=father;
			mp[father]=id++;
		}
		if(mp[son]==0)
		{
			peoples[id]=son;
			mp[son]=id++;
		}
		edge[mp[father]].push_back(mp[son]);
	}
	id--;
	//cout<<id<<endl;
}

int val[N];
int depth[N];
int first[N];
int id2=1;
void dfs(int curr,int dep)
{
	val[id2]=curr; depth[id2]=dep; first[curr]=id2; id2++; 

	for(int i=0;i<edge[curr].size();++i)
	{
		dfs(edge[curr][i],dep+1);
		//递归完子树之后还有事做 
		val[id2]=curr; depth[id2]=dep; id2++;
	} 
}

int rmq[N][30];
void whatisrmq()
{
	for(int i=0;i<=id2;++i)
	{
		for(int j=0;j<=5;++j)
		{
			cout<<rmq[i][j]<<" ";
		}
		cout<<endl;
	}
}
void rmqBuild()
{
	memset(rmq,1,sizeof(rmq));
	id2--; 
	for(int i=1;i<=id2;++i)
	{
		//rmq[i][0]=depth[i];
		rmq[i][0]=i;
	}
	for(int i=1;(1<<i)<=id2;++i)
	{
		for(int j=1;j+(1<<i)-1<=id2;++j)
		{
			if(depth[rmq[j][i-1]]<depth[rmq[j+(1<<(i-1))][i-1]])
				rmq[j][i]=rmq[j][i-1];
			else
				rmq[j][i]=rmq[j+(1<<(i-1))][i-1];
		}
	}
	//whatisrmq();
}

int rmqQuery()
{
	int m;
	cin>>m;
	while(m--)
	{
		string a,b;
		cin>>a>>b;
		int l=first[mp[a]];
		int r=first[mp[b]];
		if(l>r) swap(l,r);
		//cout<<"l,r: "<<l<<" "<<r<<endl; 
		int m = (int)log2(r-l+1);
		int index=depth[rmq[l][m]]<depth[rmq[r-(1<<m)+1][m]]?rmq[l][m]:rmq[r-(1<<m)+1][m];
		//cout<<"index "<<rmq[l][m]<<" "<<rmq[r-(1<<m)+1][m]<<" "<<index<<endl;
		cout<<peoples[val[index]]<<endl;
	}
}
void whatis()
{
	for(int i=1;i<id*2;++i)
	{
		cout<<val[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<id*2;++i)
	{
		cout<<depth[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<id+1;++i)
	{
		cout<<first[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	input();
	//要从树根开始dfs 
	dfs(1,0);
	//whatis();
	rmqBuild();
	//whatis();
	rmqQuery();
	return 0;
}
