//code chef
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	int maxn,minn;
	maxn=0;minn=1e9;
	for(int i=0;i<n;++i)
	{
		int a;
		scanf("%d",&a);
		maxn=max(a,maxn);
		minn=min(a,minn);
	}
	for(int i=0;i<q;++i)
	{
		int a;
		scanf("%d",&a);
		if(a<=maxn&&a>=minn)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
