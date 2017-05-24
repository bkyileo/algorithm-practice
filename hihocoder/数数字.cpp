#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,d,n;
        //aaaa(n) * b ÓĞ¼¸¸öd;
        cin>>a>>b>>d>>n;
        int ans=0;
        if(a*b<10)
        {
            if(a*b==d)
                cout<<n<<endl;
            if(a*b!=d)
                cout<<0<<endl;
        }
        if(a*b>=10 && a*b%10+a*b/10 < 10)
        {
            if(a*b%10==d)
                ans+=1;
            if(a*b/10==d)
                ans+=1;
            if(a*b%10+a*b/10==d)
            {
                ans+=n;
                ans-=1;
            }
            cout<<ans<<endl;
        }
        if(a*b>=10 && a*b%10+a*b/10 >= 10)
        {
            if( a*b%10==d )
                ans+=1;
            if( (a*b%10+a*b/10)%10 ==d )
                ans+=1;
            if( a*b/10+1 ==d )
                ans+=1;
            if( (a*b%10+a*b/10)%10+1 ==d )
            {
                ans+=n;
                ans-=2;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
