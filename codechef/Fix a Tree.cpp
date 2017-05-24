//codeforces Fix a Tree
#include<bits/stdc++.h>
using namespace std;
bool visit[200005];
int father[200005];
bool curr[200005];
int main()
{
	int n,now;cin>>n;
	int root=0;
	for(int i=1;i<=n;++i)
	{
		cin>>now;
		father[i]=now;
		if(i==now)root=i;
	}
	int res=0;
	visit[root]=true;
	for(int i=1;i<=n;++i)
	{
		memset(curr,false,sizeof(curr));
		now=i;
		if(!visit[now])
		{
			while(!visit[now]&&!curr[now])
			{
				visit[now]=true;
				curr[now]=true;
				now=father[now];
			}
			if(curr[now]){
				res++;
				if(root==0){
					root=now;
				}
				father[now]=root;
			}
		}
	}
	cout<<res<<endl;
	for(int i=1;i<=n;++i)
	cout<<father[i]<<" ";
	cout<<endl; 
	return 0;
}
