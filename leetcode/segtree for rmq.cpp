// segtree expore
#include <bits/stdc++.h>
using namespace std;
struct Tree {
    int l, r;
    int mx;
};

Tree seg[50];
int val[10]={0,9,1,8,2,7,3,6,4,5};

void build(int id, int L, int R) {
    seg[id].l = L;
    seg[id].r = R;
    if (L == R) {
        seg[id].mx = val[L];
    } else {
        int mid = (L + R) / 2;
        build(id * 2, L, mid);
        build(id * 2 + 1, mid + 1, R);
        seg[id].mx = max(seg[id * 2].mx, seg[id * 2 + 1].mx);
    }
}

int query(int id, int L, int R) {
    if (seg[id].r < L || seg[id].l > R) return 0;
    if (seg[id].l >= L && seg[id].r <= R) {
        return seg[id].mx;
    }
    return max(query(id * 2, L, R), query(id * 2 + 1, L, R));
}
int main()
{
	build(1,0,9);
	for(auto i:seg)
	{
		cout<<i.mx<<" "; 
	}
	cout<<endl;
	cout<<query(1,4,7)<<endl;
}
