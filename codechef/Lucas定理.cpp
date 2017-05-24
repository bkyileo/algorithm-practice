#include<bits/stdc++.h>   
using namespace std;    
#define maxn 100010    
#define LL long long 
#define p 1000000007      
LL Pow(LL a,LL b,LL mod)    
{    
    LL ans=1;    
    while(b)    
    {    
        if(b&1)   ans=(ans*a)%mod;    
        b/=2;    
        a=(a*a)%mod;    
    }    
    return ans;    
}    
LL C(LL n,LL m)    
{    
    if(n<m)    
        return 0;    
    LL ans=1;    
    for(int i=1;i<=m;i++)    
    {    
        ans=ans*(((n-m+i)%p)*Pow(i,p-2,p)%p)%p;    
    }    
    return ans;    
}    
LL Lucas(LL n,LL m)    
{    
    if(m==0)    
        return 1;    
    return (Lucas(n/p,m/p)*C(n%p,m%p))%p;    
}    
int main()    
{    
	LL m,n; 
    int t;    
    cin>>t;    
    while(t--)    
    {    
        cin>>n>>m;   
        cout<<Lucas(n,m)<<endl;    
    }    
    return 0;    
}   
