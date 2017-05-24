#include<bits/stdc++.h>
using namespace std;
struct node
{
 int l;
 int r;
 int val;
};
node tree[400005];
void build(int id,int l,int r)
{
 tree[id].l=l;tree[id].r=r;
 
 if(l==r){tree[id].val=0;return;}
 build(2*id,l,(l+r)/2);
 build(2*id+1,(l+r)/2+1,r);
 tree[id].val=0;
}
void pushDown(int curr)
{

        tree[curr*2].val += tree[curr].val;
        tree[curr*2+1].val += tree[curr].val;
	tree[curr].val=0;
}
int query(int id,int l,int r)
{
 if(tree[id].l>r || tree[id].r<l)
  return 0;
 if(tree[id].l>=l && tree[id].r<=r)
  return tree[id].val;
 pushDown(id);
 return max(query(2*id,l,r),query(2*id+1,l,r));
}

void update(int id,int l,int r)
{
 if(tree[id].l>r || tree[id].r<l)
  return ;
 if(tree[id].l>=l && tree[id].r<=r)
 {
  tree[id].val++;
  return ;
 }
 update(2*id,l,r);
 update(2*id+1,l,r);
}
int main()
{	
	
	build(1,1,10);
	
	update(1,1,5);
	update(1,3,5);
	update(1,7,9);
	
	cout<<query(1,1,1)<<endl;
	cout<<query(1,3,3)<<endl;
	cout<<query(1,4,4)<<endl;
	cout<<query(1,6,6)<<endl;
	cout<<query(1,7,7)<<endl;
}

