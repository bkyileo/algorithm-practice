#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,c,d,l;cin>>t;
	while(t--)
	{
		cin>>c>>d>>l;
		//min (dog+cat-2*dog)*4
		//max (dog+cat)*4
		if((l>=(d+max(0LL,(c-2*d)))*4)&&(l<=(c+d)*4)&&!(l%4))cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
 } 
