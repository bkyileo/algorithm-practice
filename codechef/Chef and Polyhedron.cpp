//code chef Chef and Polyhedron
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define LL long long
//波利亚计数定理
LL fastPow(LL n, LL M)
{
    LL result = 1;
    while( M>0 )
    {
        if( M & 1 ) 
            result = ( result * n ) % mod;
        M = M>>1;
        n = ( n * n ) % mod;
    }
    return result;
}

int main()
{
	int n,c;
	cin>>n>>c;
	/*
	vector<vector<int>> arrs;
	for(int i=0;i<n;++i)
	{
		int k;cin>>k;
		vector<int> curr(k);	
		for(int j=0;j<k;++k)
		{
			cin>>curr[j];
		}
		arrs.push_back(curr);
	}
	*/
	LL res=0;
	if(n==4)
	{
		res=(fastPow(c,4)+8*fastPow(c,2)% mod+3*fastPow(c,2)% mod)% mod*fastPow(12,mod-2)% mod;
	}
	if(n==6)
	{
		res=(fastPow(c,6)+6*fastPow(c,3)% mod+3*fastPow(c,4)% mod+6*fastPow(c,3)% mod+8*fastPow(c,2)% mod)% mod*fastPow(24,mod-2)% mod;
	}
	if(n==8)
	{
		res=(fastPow(c,8)+6*fastPow(c,2)% mod+3*fastPow(c,4)% mod+6*fastPow(c,4)% mod+8*fastPow(c,4)% mod)% mod*fastPow(24,mod-2)% mod;
	}
	if(n==12)
	{
		res=(fastPow(c,12)+24*fastPow(c,4)% mod+15*fastPow(c,6)% mod+20*fastPow(c,4)% mod)% mod*fastPow(60,mod-2)% mod;
	}
	if(n==20)
	{
		res=(fastPow(c,20)+24*fastPow(c,4)% mod+15*fastPow(c,10)% mod+20*fastPow(c,8)% mod)% mod*fastPow(60,mod-2)% mod;
	}
	cout<<res<<endl;
	return 0;	
} 
