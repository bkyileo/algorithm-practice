//code chef Evaluate the polynomial
#include<bits/stdc++.h>
using namespace std;
#define mod 786433
// pow 用分治 直接暴力解的 
long long poww(int index,int i)
{
	if(i==0)
		return 1;
	long long temp=poww(index,i/2);
	if(i%2==1)
	{
		return temp*temp%mod*index%mod;  
	}
	else
	{
		return temp*temp%mod; 
	}
}
void slove()
{
	int n;cin>>n;
	vector<int> arr(n+1);
	for(int i=0;i<=n;++i)cin>>arr[i];
	int q;cin>>q;
	while(q--)
	{
		int index;cin>>index;
		long long res=0;
		for(int i=0;i<=n;++i)
		{
			res+=arr[i]*poww(index,i);
			res=res%mod;
		}
		cout<<res<<endl;	
	}
}
// 优化算法1 变换多项式方法 
void slove2()
{
	int n;cin>>n;
	vector<int> arr(n+1);
	for(int i=0;i<=n;++i)cin>>arr[i];
	int q;cin>>q;
	while(q--)
	{
		int index;cin>>index;
		long long res=0;
		for(int i=n;i>0;--i)
		{
			res+=arr[i];
			res*=index;
			res=res%mod;
		}
		res+=arr[0];
		res=res%mod;
		cout<<res<<endl;	
	}		
} 
int main()
{
	slove();
	return 0;
}
