#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		long long res = 1;
		long long u,v;
		cin>>u>>v;
		res += (2 + u + v) * (1 + u + v)/2;
		res -= (v + 1);
		cout << res << endl;
	}
	return 0;
} 
