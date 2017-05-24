#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;cin>>t;
int n,m,c,res;
while(t--)
{
	res=0;
	cin>>n>>m>>c;
	for(int i=1;i<=n;++i)
	{if(c%i==0&&c/i>0&&c/i<=m){res++;}}
	cout<<res<<endl;
}
return 0;
}
