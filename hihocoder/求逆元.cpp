// code chef ����Ԫ
#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
//����С���� 
int inverse(int a)
{
	int pow = MOD - 2;
	long long act = a , res = 1;
	while( pow )
	{
		if(pow&1)
		{
			res *= act;
			res %= MOD;
		}
		act *= act;
		act %= MOD;
		pow >>= 1;
	}
	return res;
}
int main()
{
	int a=(6*inverse(6))%MOD;
	cout<<a<<" "<<inverse(6)<<endl;
	return 0;
} 
