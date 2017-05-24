//codeforces Cells Not Under Attack
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;cin>>n>>m;
	set<int> xs;
	set<int> ys;
	int x,y;
	long long res;
	for(int i=0;i<m;++i)
	{
		cin>>x>>y;
		xs.insert(x);
		ys.insert(y);
		res=n*n;
		res=res-(long long)xs.size()*n-(long long)ys.size()*n+(long long)xs.size()*ys.size();
		cout<<res<<" ";
	}
	cout<<endl;
	return 0;
}
