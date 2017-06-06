#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int mod = 1000000007;
vector<int> A;
vector<int> B;
vector<int> C;
int main()
{
	std::ios::sync_with_stdio(false);
	int t;cin >> t;
	long long posA;
	long long posC;
	int res;
	int p , q , r ;
	while( t-- )
	{
		cin >> p >> q >> r;
		//scanf ("%d %d %d",&p,&q,&r);
		A = vector<int>(p);
		B = vector<int>(q);
		C = vector<int>(r);
		for(int i=0 ; i<p ; ++i)cin >> A[i];//scanf ("%d",&A[i]);//
		for(int i=0 ; i<q ; ++i)cin >> B[i];//scanf ("%d",&B[i]);//
		for(int i=0 ; i<r ; ++i)cin >> C[i];//scanf ("%d",&C[i]);//
		sort(A.begin() , A.end());
		sort(B.begin() , B.end());
		sort(C.begin() , C.end());
		vector<int> sumA(A);
		for(int i=1;i<p;++i)
		{
			sumA[i] = sumA[i]+sumA[i-1];
			if(sumA[i]>mod) sumA[i] -= mod;
		}
		vector<int> sumC(C);
		for(int i=1;i<r;++i)
		{
			sumC[i] = sumC[i]+sumC[i-1];
			if(sumC[i]>mod) sumC[i] -= mod;
		}
		res = 0;
		for(int i=q-1;i>=0;--i)
		{
			posA = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
			posC = upper_bound(C.begin(), C.end(), B[i]) - C.begin();
			if(posA == 0 || posC == 0)break;
			res += (((posC * B[i])%mod + sumC[posC - 1])%mod * ((posA * B[i])%mod + sumA[posA - 1])%mod)%mod;
			res = res % mod;
		}
		cout<<res<<endl;
	}
	return 0;
}
