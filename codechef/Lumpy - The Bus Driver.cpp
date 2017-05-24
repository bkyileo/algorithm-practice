//code chef Lumpy - The Bus Driver
#include<bits/stdc++.h>
using namespace std;
int arr[100005];
long long n,p,q;
int curr,res;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>p>>q;
		res=0;
		for(int i=0;i<n;++i)
		cin>>arr[i];
		sort(arr,arr+n);
		for(int i=0;i<n;++i)
		{
			if(arr[i]%2==1)
			{
				if(q>=arr[i]/2&&p)
				{
					p--;
					q-=arr[i]/2;
					res++;
				}
				else if(2*q+p>=arr[i]&&p)
				{
					p-=arr[i]-2*q;
					assert(p>=0);
					q=0;
					res++;
				}
			}
			if(arr[i]%2==0)
			{
				if(q>=arr[i]/2)
				{
					q-=arr[i]/2;
					res++;
				}
				else if(2*q+p>=arr[i]&&p)
				{
					p-=arr[i]-2*q;
					assert(p>=0);
					q=0;
					res++;
				}
			}	
		}
		cout<<res<<endl;
	}
}
