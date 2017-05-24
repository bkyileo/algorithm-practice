// code chef Chef and Circle Run
#include<bits/stdc++.h>
using namespace std;
int helper(vector<int> arr)
{
	int sm=0;
	for(auto i:arr)sm+=i;

	int gmax=0;
	int lmax=0;
	for(auto i:arr)
	{
		lmax+=i;
		if(lmax<0)lmax=0;
		if(gmax<lmax)gmax=lmax;
	}
	return 2*(sm-gmax);
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;++i)cin>>arr[i];
		int s,e;cin>>s>>e;
		s--;e--;
		if (s>e)swap(s,e);
		
		int path1;path1=0;
		for(int i=s;i<e;++i)
			path1+=arr[i];
		//cout<<"temp1 "<<path1<<endl;
		vector<int> temp;
		for(int i=e;i<n+s;++i)
			temp.push_back(arr[i%n]);
		//for(auto i:temp)cout<<i<<" ";cout<<endl;
		path1+=helper(temp);
		//cout<<"path1 "<<path1<<endl;
		
		int path2;path2=0;
		for(int i=e;i<s+n;++i)
			path2+=arr[i%n];
			
		//cout<<"temp2 "<<path2<<endl;
		vector<int> temp2;
		for(int i=s;i<e;++i)
			temp2.push_back(arr[i]);
		//for(auto i:temp2)cout<<i<<" ";cout<<endl;	
		path2+=helper(temp2);
		//cout<<"path2 "<<path2<<endl;
		
		cout<<min(path1,path2)<<endl;
	}
	return 0;
}

