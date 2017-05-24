#include<bits/stdc++.h>
using namespace std;
#define N 400005
// AC 90% 不知道什么原因 

struct node
{
	int l;
	int r;
	int mx;
	int lazyMask; 
};
int arr[100005];
node tree[N];
void build(int id,int l,int r)
{
	tree[id].l=l;tree[id].r=r;
	tree[id].lazyMask=0;
	if(l==r)
	{
		tree[id].mx=arr[l];
		return ;
	}
	build(2*id,l,(l+r)/2);
	build(2*id+1,(l+r)/2+1,r);
	tree[id].mx=max(tree[2*id].mx,tree[id*2+1].mx);
}
void pushDown(int curr)
{
    if(tree[curr].lazyMask != 0)
    {
        tree[curr*2].lazyMask += tree[curr].lazyMask;
        tree[curr*2+1].lazyMask += tree[curr].lazyMask;

        tree[curr*2].mx += tree[curr].lazyMask;
        tree[curr*2+1].mx += tree[curr].lazyMask;

        tree[curr].lazyMask = 0;
    }
}
int query(int id,int l,int r)
{
	if(tree[id].l>r || tree[id].r<l)
		return 0;
	if(tree[id].l>=l && tree[id].r<=r)
		return tree[id].mx;
	pushDown(id);	
	return max(query(2*id,l,r),query(2*id+1,l,r));
}

void update(int id,int l,int r,int val)
{
	if(tree[id].l>r || tree[id].r<l)
		return ;
	if(tree[id].l>=l && tree[id].r<=r)
	{
		tree[id].mx += val;
		tree[id].lazyMask += val;
		return ;
	}
	pushDown(id);
	update(2*id,l,r,val);
	update(2*id+1,l,r,val);
	tree[id].mx=max(tree[2*id].mx,tree[id*2+1].mx);	
} 

struct task
{
	int b;
	int e;
};



task temp[100004];
int scatter[200010];

int main()
{
	//1000000000
	memset(arr,0,sizeof(arr));
	build(1,0,100004);
	int n;
	scanf("%d",&n);
	int index=0;
	for(int i=0;i<n;++i)
	{
		int b,e;
		scanf("%d%d",&temp[i].b,&temp[i].e);
		scatter[index++] = temp[i].b;
		scatter[index++] = temp[i].e ;
	}
	sort(scatter,scatter+index);
	int size=unique(scatter,scatter+index)-scatter;
	for(int i=0;i<n;++i)
	{
		int x = lower_bound(scatter, scatter + index, temp[i].b) - scatter;  
      	int y = lower_bound(scatter, scatter + index, temp[i].e) - scatter;  
//		int x=temp[i].b;
//		int y=temp[i].e;
		cout<<x<<" "<<y<<endl;
		update(1,x,y-1,1);
	}
	cout<<query(1,0,100004)<<endl;
	return 0;
}

/*
5
1 10
2 7
6 9
3 4
7 10
*/
