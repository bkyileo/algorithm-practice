//code chef 
#include<bits/stdc++.h>
using namespace std;
#define N 400020
#define M 100005
struct node
{
	int l,r;
	unordered_map<int,int> mp;
	int d;
};
node tree[N];
int arr[M];
vector<int> stat;
void build(int id,int l,int r)
{
	tree[id].l=l;
	tree[id].r=r;
	if(l==r)
	{
		tree[id].mp.clear();
		tree[id].mp[arr[l]]++;
		tree[id].d=arr[l];
	}
	else
	{
		int mid=(l+r)/2;
		build(2*id,l,mid);
		build(2*id+1,mid+1,r);
		
		tree[id].mp.clear();
		for(auto i:tree[2*id].mp)
			tree[id].mp[i.first]+=i.second;
		for(auto i:tree[2*id+1].mp)
			tree[id].mp[i.first]+=i.second;
		
		if(tree[id].mp[tree[2*id].d]>(r-l+1)/2)
			tree[id].d=tree[2*id].d;
		else if(tree[id].mp[tree[2*id+1].d]>(r-l+1)/2)
			tree[id].d=tree[2*id+1].d;
		else
			tree[id].d=-1;
	}
}
void update(int id,int l,int r,int val,int old)
{
	if(tree[id].r<l||tree[id].l>r)return ;
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].mp.clear(); 
		tree[id].mp[val]++;
		tree[id].d=val;
		return ;
	}
	update(2*id,l,r,val,old);
	update(2*id+1,l,r,val,old);
	tree[id].mp[old]-=1;
	tree[id].mp[val]+=1;
	//curr l&r
	if(tree[id].mp[tree[2*id].d]>(tree[id].r-tree[id].l+1)/2)
		tree[id].d=tree[2*id].d;
	else if(tree[id].mp[tree[2*id+1].d]>(tree[id].r-tree[id].l+1)/2)
		tree[id].d=tree[2*id+1].d;
	else 
		tree[id].d=-1;
	return ;
}
void query(int id,int l,int r)
{
	
	if(tree[id].r<l||tree[id].l>r)return ;
	if(tree[id].l>=l && tree[id].r<=r)
	{
		stat.push_back(id);
		return ;
	}
	query(2*id,l,r);
	query(2*id+1,l,r);
	return ;
}
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>arr[i];
	build(1,1,n);
	for(int i=0;i<q;++i)
	{
		int a,b,c;cin>>a>>b>>c;
		if(a==1)
		{ 
			update(1,b,b,c,arr[b]);
			arr[b]=c;
		}
		if(a==2)
		{
			stat.clear();
			query(1,b,c);
			bool flag=false;
			for(auto j:stat)
			{
				int count=0;
				for(auto k:stat)
					count+=tree[k].mp[tree[j].d];
				if(count>(c-b+1)/2)
				{
					flag=true;
					break;
				}
			}
			if(flag)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
