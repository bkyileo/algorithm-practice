//codeforces cards
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin>>n;
	vector<int> arr(n);
	vector<bool> visit(n,false);
	int sums=0;
	for(int i=0;i<n;++i){cin>>arr[i];sums+=arr[i];}
	sums=sums/(n/2);
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		if(visit[i]==false && visit[j]==false && arr[i]+arr[j]==sums)
		{
			if(arr[j]<arr[i])
			cout<<j+1<<" "<<i+1<<endl;
			else
			cout<<i+1<<" "<<j+1<<endl;

			visit[i]=true;
			visit[j]=true;
		}
	}
	return 0;
}
