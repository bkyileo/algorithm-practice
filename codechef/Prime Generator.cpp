//Prime Generator
#include<bits/stdc++.h>
using namespace std;
bool primes[100005];
vector<int> vt;
void init()
{
	memset(primes,true,sizeof(primes));
	primes[0]=false;primes[1]=false;
	for(int i=2;i<100005;++i)
	{
		if(primes[i])
		{
			for(int j=2;i*j<100005;++j)primes[i*j]=false;
		}
	}
	for(int i=0;i<100005;++i)if(primes[i])vt.push_back(i);
	//for(int i=0;i<vt.size();++i)cout<<vt[i]<<" ";cout<<endl;
}
int main()
{
	init();
	int t;cin>>t;
	while(t--)
	{
		int m,n;cin>>m>>n;
		vector<bool> p(n-m+1,true);
		for(int i=0;i<vt.size();++i)
		{
			int k=m/vt[i];
			for(int j=k;k*vt[i]<=n;++k)
			{	
				if(k*vt[i]-m>=0&&k!=1)p[k*vt[i]-m]=false;
			}
		}
		for(int i=m;i<=n;++i)if(p[i-m]&&i!=1)printf("%d\n",i);
	}
	return 0;
}
