#include<bits/stdc++.h>
using namespace std;
long long temp[200005];
int main()
{
	int n,m;
	cin>>n>>m;
	vector<long long> arr1(n);
	vector<long long> arr2(m);
	for(int i=0;i<n;++i)cin>>arr1[i];
	for(int i=0;i<m;++i)cin>>arr2[i];
	long long res=0;
	int lastj=0;
	int currindex=1;
	int i=0;int j=0;
	temp[0]=INT_MIN;
	while(i<n&&j<m)
	{
		if(arr1[i]<arr2[j])
			temp[currindex++]=arr1[i++];
		else
		{
			temp[currindex]=arr2[j++];
			for(int k=lastj+1;k<currindex;++k)
			{
				if(lastj==0)
				{
					res=max(res,temp[currindex]-temp[k]);
				}
				else
				{
					res=max(res,min(temp[k]-temp[lastj],temp[currindex]-temp[k]));
				}
			}
			lastj=currindex;
			currindex++;
		}	
	}
	if(i==n)
	{
		temp[currindex]=arr2[j++];
		for(int k=lastj+1;k<currindex;++k)
		{
			if(lastj==0)
			{
				res=max(res,temp[currindex]-temp[k]);
			}
			else
			{
				res=max(res,min(temp[k]-temp[lastj],temp[currindex]-temp[k]));
			}
		}
	}
	else if(j==m)
	{
		res=max(res,arr1[n-1]-arr2[m-1]);
	}
	cout<<res<<endl;
	return 0;
}
