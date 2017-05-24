// code forces As Fast As Possible
#include<bits/stdc++.h>
using namespace std;
bool check(double mid,double l,double v1,double v2,int batch)
{
	return l-(2*mid)/(v1+v2)*(batch-1)*v1-mid>1e-9;
}
int main()
{
	double n,l,v1,v2,k;
	cin>>n>>l>>v1>>v2>>k;
	double left=0;
	double right=l;
	int batch=(int)n/k;
	if((int)n%(int)k)batch++;
	//if(batch==1){cout<<l/v2<<endl;return 0;}
	while(right-left>1e-9)
	{
		double mid=(left+right)/2;
		if(check(mid,l,v1,v2,batch))
		{
			left=mid;
		}
		else
		{
			right=mid;
		}
	}
	//cout<<left<<endl;
	double time =left/v2+(l-left)/v1;
	cout<<setprecision(15)<<time<<endl;
	return 0;
}
