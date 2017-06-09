//Êı×éÖØÅÅ2
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	vector<int>	arr(n);
	for(int i=0;i<n;++i)cin>>arr[i];
	vector<int>	tp(arr);
	sort(tp.begin(),tp.end());
	int res=0;
	int localmax=arr[0];
	for(int i=1;i<n;++i)
	{
		if(localmax<=arr[i])localmax=arr[i];
		else 
		{
			int pos=lower_bound(tp.begin(),tp.end(),arr[i])-tp.begin();
			res=max(res,pos+1);
		}
	}
	cout<<res<<endl;
	return 0;
} 
