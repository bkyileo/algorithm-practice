//code chef Chef and easy problem 2
#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
bool p[1000005];
void init()
{
	memset(p,true,sizeof(p));
	p[0]=false;p[1]=false;
	for(int i=2;i<1000005;++i)
	{
		if(!p[i])continue;
		else
		{
			for(int j=2;i*j<1000005;++j)p[i*j]=false;
		}
	}
	for(int i=2;i<1010;++i)if(p[i])primes.push_back(i);
	//for(auto i:primes)cout<<i<<" ";cout<<endl;
}
int main()
{
	init();
	int t;cin>>t;
	while(t--)
	{
		vector<int> count(1000005,0);
		int n;cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;++i)cin>>arr[i];
		for(int i=0;i<n;++i)
		{
			if(p[arr[i]])
			{
				if(count[arr[i]]==0)count[arr[i]]++;
			}
			else
			{
				for(int j=0;j<primes.size();++j)
				{
					if(primes[j]>arr[i])break;
					int curr=0;
					while(arr[i]%primes[j]==0)
					{
						curr++;
						arr[i]=arr[i]/primes[j];
					}
					count[primes[j]]=max(count[primes[j]],curr);
				}
				//只会出现一次 
				if(p[arr[i]])
				{
					if(count[arr[i]]==0)count[arr[i]]++;
				}
			}
		}
		int res=0;
		for(auto i:count){
			res+=i;
		}
		cout<<res<<endl;
	}
	return 0;
}
