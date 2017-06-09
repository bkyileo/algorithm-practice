#include<bits/stdc++.h>
using namespace std;
bool primes[100005];
vector<int> vt;
void init()
{
	memset(primes,true,sizeof(primes));
	primes[0]=false;primes[1]=false;
	for(int i=2;i<100005;++i)
	{
		if(primes[i])
		{
			for(int j=2;i*j<100005;++j)primes[i*j]=false;
		}
	}
	for(int i=0;i<100005;++i)if(primes[i])vt.push_back(i);
}
struct Tree {
    int l, r;
    double sum;
};
Tree seg[100005*4];
double arr[100005];
void build(int id, int L, int R) {
    seg[id].l = L;
    seg[id].r = R;
    if (L == R) {
        seg[id].sum = arr[L];
    } else {
        int mid = (L + R) / 2;
        build(id * 2, L, mid);
        build(id * 2 + 1, mid + 1, R);
        seg[id].sum = seg[id * 2].sum+seg[id * 2 + 1].sum;
    }
}
double query(int id, int L, int R) {
    if (seg[id].r < L || seg[id].l > R) return 0.0;
    if (seg[id].l >= L && seg[id].r <= R) {
        return seg[id].sum;
    }
    return query(id * 2, L, R)+query(id * 2 + 1, L, R);
}
double decimal(double a)
{
	return a-int(a);
}
bool isint(double a)
{
	if(abs(a-round(a))<1e-12)return true;
	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
	init();
	int n,curr;cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>curr;
		arr[i]=log10(curr);
	}
	build(1,1,n);
	int k;cin>>k;
	int l,r,x,y,res;
	double tp;
	for(int i=0;i<k;++i)
	{
		cin >> l >> r >> x >> y;
		res = 0;
		int poss = lower_bound(vt.begin(),vt.end(),x)-vt.begin();
		int pose = upper_bound(vt.begin(),vt.end(),y)-vt.begin();
		tp = query(1,l,r);
		for(int j=poss;j<pose;++j)
		{
			while(isint(pow(10,tp-log10(vt[j]))))
				{
					tp-=log10(vt[j]);
					res++;
				}
		}
		cout<<res<<endl;
	}
	return 0;
} 
