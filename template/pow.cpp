#include<bits/stdc++.h>
using namespace std;
float _pow(float a,int n)
{
	if(n==0) return 1.0;
	float tp = _pow(a,n/2);
	if(n%2) return tp*tp*a;
	else return tp*tp;
}
bool pow(float a,int n,float& res)
{
	if(abs(a) < 1e-20 && n==0) return false;
	if(n==0) 
	{
		res=1.0;
		return true;
	}
	bool flag = n>0 ? true:false;
	if(!flag) res = 1.0 / _pow(abs(a),abs(n));
	else res = _pow(abs(a),abs(n));
	return true;
}
int main()
{
	float res;
	if(pow(0,0,res))
	cout<<res<<endl;
	return 0;
} 
