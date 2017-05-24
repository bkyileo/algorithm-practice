//code chef
#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
#define LL long long 
LL factorial[100005];
LL inverse[100005];
LL fastPow(LL n, LL M)
{
    LL result = 1;
    while( M>0 )
    {
        if( M & 1 ) 
            result = ( result * n ) % p;
        M = M>>1;
        n = ( n * n ) % p;
    }
    return result;
}
LL poww(LL index,LL i)
{
	LL temp;
	if(i==0)
		return 1;
	temp=poww(index,i/2);
	if(i%2==1)
	{
		//这里没有做余数 
		return temp*temp%p*index%p;  
	}
	else
	{
		return temp*temp%p; 
	}
}
void init()
{
	factorial[0]=1;inverse[0]=1;
	for(LL i=1;i<100005;++i)
	{
		factorial[i]=factorial[i-1]*i%p;
		inverse[i]=poww(factorial[i],p-2);	
	}
} 

void subtask2(int n,int k,int zeros)
{
	if(zeros==0)
	{
		if(n>k)
		{
			LL res=0;
			for(int i=k;i>=0;i=i-2)
			{
				res+=factorial[n]*inverse[i]%p*inverse[n-i]%p;
				res=res%p;
			}
			cout<<res<<endl;
		}
		if(k>=n)
		{
			LL res=1;
			while(--n)
			{
				res=res<<1;
				res=res%p;
			}
			cout<<res<<endl;
		}
	}
	else
	{
		n=n-zeros;
		if(n>k)
		{
			LL res=0;
			for(int i=k;i>=0;i--)
			{
				res+=factorial[n]*inverse[i]%p*inverse[n-i]%p;
				res=res%p;
			}
			cout<<res<<endl;
		}
		if(k>=n)
		{
			LL res=1;
			while(n--)
			{
				res=res<<1;
				res=res%p;
			}
			cout<<res<<endl;
		}
	}
}    

int main()
{
	init();
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> arr(n);
		int zeros=0;
		for(int i=0;i<n;++i)
		{
			int a;cin>>a;
			if(a==0) zeros++;
			arr[i]=a;
		}
		subtask2(n,k,zeros);
	}	
} 
