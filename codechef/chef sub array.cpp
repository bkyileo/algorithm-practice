//Chef and Sub Array
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ts;
int get(int b,int e);
int main()
{
	int n,k,p;
	cin>>n>>k>>p;
	vector<int> arr(n);
	for(int i=0;i<n;++i)cin>>arr[i];
	/* find cicle sum */
	if(k<n)
	{
		vector<int> mask(n,0);
		for(int i=0;i<k;++i)
		{
			mask[0]+=arr[i];
		}
		for(int i=1;i<n;++i)
		{
			mask[i]=mask[i-1]+arr[(i+k-1)%n]-arr[i-1];
		}
		ts=vector<vector<int>>(25,vector<int>(n));
		ts[0]=mask;
		for(int i=1;(1<<i)<=n;++i)
		{
			for(int j=0;j+(1<<i)<=n;j++)
			{
				ts[i][j]=max(ts[i-1][j],ts[i-1][(1<<i-1)+j]);
			}
		}
		int move=0;
		for(int i=0;i<p;++i)
		{
			char ch;cin>>ch;
			if(ch=='!')move++;
			else
			{
				int s1,e1;
				if(move%n==0){s1=0;}
				else{s1=n-move%n;}
				if(s1+n-k>=n)
				{
					int s2,e2;e1=n-1;
					s2=0;e2=n-k-move%n;
					cout<<max(get(s1,e1),get(s2,e2))<<endl;
				}
				else
				{
					e1=s1+n-k;
					cout<<get(s1,e1)<<endl;
				}
			}
		}
	}
	else
	{
		int res=0;
		for(auto i:arr)if(i==1)res++;
		for(int i=0;i<p;++i)
		{
			char ch;cin>>ch;
			if(ch=='?')cout<<res<<endl;;
		}
	}
	return 0;
}
int get(int b,int e){
	if(b>e)return 0;
    int i=(int)log2(e - b+1);
    return max(ts[i][b],ts[i][e-(1<<i)+1]); 
}
