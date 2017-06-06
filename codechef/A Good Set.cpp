#include<bits/stdc++.h>
using namespace std;
void slove(int n)
{
	vector<int> mask(1000,0);
	for(int i=1;n>0;++i)
	{
		if(mask[i]==0)
		{
			cout<<i<<" ";
			mask[i]=1;
			for(int j=0;j<i;++j)
				if(mask[j]==1)
					mask[i+j]=2;
			n--;
		}
	}
	cout<<endl;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		slove(n);
	}
	return 0;	
} 
