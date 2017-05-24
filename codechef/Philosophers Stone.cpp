// spoj Philosophers Stone
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	//cin>>t;
	while(t--)
	{
		int row,col;
		scanf("%d%d",&row,&col);
		//cin>>row>>col;
		vector<int> pass(col+2,0);
		vector<int> curr(col+2,0);
		for(int i=1;i<=col;++i)
		{
			scanf("%d",&pass[i]);
			//cin>>pass[i];
		}
		for(int i=1;i<row;++i)
		{
			for(int j=1;j<=col;++j)
			{
				scanf("%d",&curr[j]);
				//cin>>curr[j];
			}
			for(int j=1;j<=col;++j)
			{
				curr[j]=curr[j]+max(max(pass[j-1],pass[j]),pass[j+1]);
			}
			pass=curr;
		}
		int res=INT_MIN;
		for(int i=1;i<=col;++i)
		{
			res=max(res,pass[i]);
		}
		printf("%d\n",res);
		//cout<<res<<endl;
	}
	return 0;
} 
