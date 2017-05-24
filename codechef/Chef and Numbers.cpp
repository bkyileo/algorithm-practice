//Chef and Numbers
#include<bits/stdc++.h>
using namespace std;
int s(int x)
{
	int res=0;
	while(x)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}
int main()
{
	int n;cin>>n;
	int res=0;
	for(int i=0;i<1000;++i)
	{
		if(n-i>0&&n-i+s(n-i)+s(s(n-i))==n)
		res++;
	}
	cout<<res<<endl;
	return 0;
}
