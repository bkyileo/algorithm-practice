#include<bits/stdc++.h>
using namespace std;

//²¢²î¼¯
#define N 100005

int fa[N];

int find(int n)
{
	if (fa[n] != n)
	{
		fa[n]=find(fa[n]);
	}
	
	return fa[n];
}

void print(int n)
{
	for (int i=0;i<n;++i)
		cout<<fa[i]<<" ";
	cout<<endl;
}

int main()
{
	for (int i=0;i<N;++i)
	{
		fa[i]=i;
	}
	print(10);
	
	int relations;
	cin>>relations;
	
	while(relations--)
	{
		int n,m;
		cin>>n>>m;
		n=find(n);
		m=find(m);
		fa[n]=m;
		
	}
	print(10);	

	cout<<find(1)<<endl;
	
	return 0;
}

