#include<bits/stdc++.h>
using namespace std;
long long cost[100005];
long long arr[100005];
struct node1{
	long long l,r,val;
};
node1 tree[400005];
void build(int id,int l,long long r)
{
	tree[id].l=l;
	tree[id].r=r;
	if(l==r)
	{
		tree[id].val=arr[l];
	}
	else
	{
		int mid=(l+r)/2;
		build(id*2+1,l,mid);
		build(id*2+2,mid+1,r);
		tree[id].val=min(tree[id*2+1].val,tree[id*2+2].val);
	}
}
long long query(int id, int L, int R) {
    if (tree[id].r < L || tree[id].l > R) return 1e15;
    if (tree[id].l >= L && tree[id].r <= R) {
        return tree[id].val;
    }
    return min(query(id*2+1, L, R), query(id*2+2, L, R));
}
void update(int id,int l,int r,long long val)
{
	if(tree[id].l>r || tree[id].r<l)
		return ;
	if(tree[id].l>=l && tree[id].r<=r)
	{
		tree[id].val = val;
		return ;
	}
	update(2*id+1,l,r,val);
	update(2*id+2,l,r,val);
	tree[id].val=min(tree[2*id+1].val,tree[id*2+2].val);	
}


struct node
{
	int p;
	vector<int> s;
	vector<pair<int,int>> tks;
};
vector<node> g(100005);

void dfs(int curr,int sp)
{
	for(auto i:g[curr].tks)
	{
		int left;
		left=sp>i.first?(sp-i.first):0;
		if(cost[curr]>i.second+query(0,left,sp-1))
		{
			cost[curr]=i.second+query(0,left,sp-1);				
		}
	}
	update(0,sp,sp,cost[curr]);
	for(auto i:g[curr].s)
		dfs(i,sp+1);
	update(0,sp,sp,1e15);
}


int main()
{
	int n,m,from,to;
	cin>>n>>m;
	for(int i=1;i<n;++i)
	{
		cin>>from>>to;
		from--;to--;
		g[from].p=to;
		g[to].s.push_back(from);
	}
	
	int a,b,c;
	for(int i=0;i<m;++i)
	{
		cin>>a>>b>>c;
		a--;
		g[a].tks.push_back(make_pair(b,c));
	}
	
	cost[0]=0;arr[0]=0;
	for(int i=1;i<100005;++i){cost[i]=1e15;arr[i]=1e15;}
	build(0,0,100001);
	dfs(0,0);
	int q,curr;
	cin>>q;
	
	while(q--){
		cin>>curr;
		curr--;
		cout<<cost[curr]<<endl;
	}
	return 0;
} 
