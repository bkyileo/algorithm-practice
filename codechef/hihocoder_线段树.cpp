//hihocoder  
#include<bits/stdc++.h>
using namespace std;
#define N 4000005
struct node
{
	int l;
	int r;
	int light;
	int lazyMask; 
};
node tree[N];
int goods[100005];
void build(int id,int l,int r)
{
	tree[id].l=l;tree[id].r=r;
	tree[id].lazyMask=-1;
	if(l==r)
	{
		tree[id].light=goods[l];
		return ;
	}
	build(2*id,l,(l+r)/2);
	build(2*id+1,(l+r)/2+1,r);
	tree[id].light=tree[2*id].light+tree[id*2+1].light;
}
void pushDown(int curr)
{
    if(tree[curr].lazyMask != -1)
    {
        tree[curr*2].lazyMask = tree[curr].lazyMask;
        tree[curr*2+1].lazyMask = tree[curr].lazyMask;

        tree[curr*2].light = tree[curr].lazyMask*(tree[curr*2].r-tree[curr*2].l+1);
        tree[curr*2+1].light = tree[curr].lazyMask*(tree[curr*2+1].r-tree[curr*2+1].l+1);

        tree[curr].lazyMask = -1;
    }
}
int query(int id,int l,int r)
{
	if(tree[id].l>r || tree[id].r<l)
		return 0;
	if(tree[id].l>=l && tree[id].r<=r)
		return tree[id].light;
	pushDown(id);	
	return query(2*id,l,r)+query(2*id+1,l,r);
}

void update(int id,int l,int r,int val)
{
	if(tree[id].l>r || tree[id].r<l)
		return ;
	if(tree[id].l>=l && tree[id].r<=r)
	{
		tree[id].light = val*(tree[id].r-tree[id].l+1);
		tree[id].lazyMask = val;
		return ;
	}
	pushDown(id);
	update(2*id,l,r,val);
	update(2*id+1,l,r,val);
	tree[id].light=tree[2*id].light+tree[id*2+1].light;	
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int weight;
		scanf("%d",&weight);
		goods[i]=weight;
		
	}
	build(1,1,n);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int order;
		scanf("%d",&order);
		if(order==0)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",query(1,a,b));
		}
		if(order==1)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			update(1,a,b,c);
		}
	}
	return 0;
}
