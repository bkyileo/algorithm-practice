// code chef Easy Queries

#include<bits/stdc++.h>
using namespace std;
int A[100005];
void swap(int &a,int& b)
{
	int temp=a;
	a=b;
	b=temp;
}
int main()
{
	int N,Q,index=1;
	
	cin>>N>>Q;
	int n=N; 
	while(n--)
	{
		int a;
		cin>>a;
		A[index]=a;
		index++;
	}
	int ans=0; 
	while(Q--)
	{
		int a, b, c, d, k,l,r;
		cin>>a>>b>>c>>d>>k; 
		l=(a*max(0,ans)+b)%N+1;
		r=(c*max(0,ans)+d)%N+1;
		if(l>r) swap(l,r);
		set<int> s;
		for(int i=l;i<=r;++i)
		{
			s.insert(A[i]);
		}
		if(k>s.size())
			ans=-1;
		else
		{
			int count=0;
			for(auto i=s.begin();count<k;++i)
			{
				ans=*i;
				count++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
