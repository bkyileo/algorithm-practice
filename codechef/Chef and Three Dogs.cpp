#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;cin>>t;
while(t--)
{
double s,v;
cin>>s>>v;
//double res=((s*3.1415926)/(6*v));
//double res=sqrt(3.0)*s*3.1415926/(9.0*v);
double res=(2*s)/(3*v);
cout<<std::fixed<<setprecision(9)<<res<<endl;
}
}
