#include<bits/stdc++.h>
using namespace std;
#define N 100005
//有 bug 
/*
	1 : 输入树 done
 	2 : 计算anc跳表
	3 ：计算深度 
	4 ：计算父节点 done
	5 ：计算树根节点 done
*/ 
int father[N];
int rootmask[N];
vector<int> node[N];
map<string,int> mp;
vector<int> roots;
int id=0;
string names[N];

//跳表浪费空间 
int anc[N][30];
int dep[N];
 
void init()
{
	memset(rootmask,0,sizeof(rootmask));
	memset(dep,0,sizeof(dep));
	memset(anc,-1,sizeof(anc));
	for(int i=0;i<N;++i)
		father[i]=i;
}
void input()
{
	int n;
	cin>>n;
	names[0]="-1";
	while(n--)
	{
		string name1,name2;
		cin>>name1>>name2;
		if(mp[name1]==0)
		{
			mp[name1]=++id;
			names[id]=name1;
		}

		if(mp[name2]==0)
		{
			mp[name2]=++id;
			names[id]=name2;	
		}
		node[mp[name1]].push_back(mp[name2]);
		father[mp[name2]]=mp[name1];
		rootmask[mp[name2]]++;
	}
	//貌似不需要 roots 
	for(int i=1;i<N;++i)
	{
		if(i<id && rootmask[i]==0)
		 	roots.push_back(i);
	} 
} 
void calAnc() //初始化anc数组
{
	for (int i = 1; i <= id; i++) 
			anc[i][0] = father[id]; //边界情况，父亲
	
	for (int j = 1; (1 << j) < id; j++)
		for (int i = 0; i < id; i++)
			if (anc[i][j-1] != -1) //注意超出根节点的情况
				anc[i][j] = anc[anc[i][j-1]][j-1];
}

void calDep(int x, int y) //初始化dep数组
{
	dep[x] = y; //x为当前节点，y为深度
	for (int i = 0; i < node[x].size(); i++)
		calDep(node[x][i], y+1);
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int query(int p, int q) //查询p和q的最近公共祖先
{
	if (dep[p] < dep[q]) swap(p, q);//令p为深度较深的一个

	int log = 1; //log(dep[p])的下取整，为跳的最大距离
	while ((1 << log) <= dep[p]) log++;
	log--;

	//将p跳到与q同一层的地方
	for (int i = log; i >= 0; i--)
		if (dep[p] - (1 << i) >= dep[q])
			p = anc[p][i];

	if (p == q) return q; //检查是否和q重合

	//公共跳到最近公共祖先的下面
	for (int i = log; i >= 0; i--)
		if (anc[p][i] != -1 && anc[p][i] != anc[q][i])
			p = anc[p][i], q = anc[q][i];

	return father[p];//父亲即为最近公共祖先
}
int main()
{
	init();
	input();
	for(int i=0;i<roots.size();++i)
	{
		calDep(roots[i],0);
	}
	calAnc();
	int m;
	cin>>m;
	while(m--)
	{
		string name1,name2;
		cin>>name1>>name2;
		if(name1==name2)
			cout<<name1<<endl;
		else
			cout<<names[query(mp[name1],mp[name2])]<<endl;
	}
	return 0;
}
