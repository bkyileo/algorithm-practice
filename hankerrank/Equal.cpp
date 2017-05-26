//Equal
#include<bits/stdc++.h>
using namespace std;
void slove()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;++i)cin>>arr[i];
		int mn=INT_MAX;
		for(auto i:arr)mn=min(i,mn);
		int ress=INT_MAX;
		for(int j=mn;mn<6+j;--j)
		{
			int res=0;
			for(auto i:arr)
			{
				res+=(i-j)/5+((i-j)%5)/2+((i-j)%5)%2;
			}
			ress=min(res,ress);	
		}
		cout<<ress<<endl; 
	}
}
int main()
{
	slove();
	return 0;
}
 
