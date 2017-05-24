#include<bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor) {
	if(divisor==0)return INT_MAX;
	long long div= (long long)dividend;
	long long der= (long long)divisor;
	bool f=(div*der)>0?true:false;
	div=abs(div);
	der=abs(der);
	int res=0;
	int ct;
	while(div>=der)
	{
		long long a=der;
		ct=1;
		while(ct*der<=div)ct=ct<<1;
		ct=ct>>1;
		res+=ct;
		div-=ct*der;
	}
	return res;
}
int main()
{
	cout<<divide(1,2)<<endl;
	return 0;
}
