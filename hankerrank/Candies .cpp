#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	vector<long long> arr(n);
	for(int i=0;i<n;++i)cin>>arr[i];
	
	vector<long long> dis(n,1);
	for(int i=1;i<n;++i)
	{
		if(arr[i]>arr[i-1])dis[i]=dis[i-1]+1;
	}
	for(int i=n-2;i>-1;--i)
	{
		if(arr[i]>arr[i+1])dis[i]=max(dis[i+1]+1,dis[i]);
	}
	long long res=0;
	for(auto i:dis)res+=i;
	cout<<res<<endl;
	return 0;
} 
/* 
10
2 4 2 6 1 7 8 9 2 1
1 2 1 2 1 2 3 4 1 1
1 2 1 2 1 2 3 4 2 1
*/
