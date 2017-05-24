#include<bits/stdc++.h>
using namespace std;
int t1[1001],t2[1001];
bool m[1001][1001];
int n;
int coll[1001];
bool dfs(int curr,int la,int lb)
{
	if(curr>=n&&(la+lb==n))return true;
	
	bool flagx=true;
	for(int i=0;i<la && flagx;++i)
		if(m[curr][t1[i]]==false)flagx=false;
	if(flagx)t1[la]=curr;
	if(flagx&&dfs(curr+1,la+1,lb))return true;

	bool flagy=true;
   	for(int i=0;i<lb && flagy;++i)
       		if(m[curr][t2[i]]==false)flagy=false;
   	if(flagy)t2[lb]=curr;
   	if(flagy&&dfs(curr+1,la,lb+1))return true;
		
   	return false;

}
bool bfs(int u){
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int y=0; y<n; ++y){
           if(x==y || m[x][y]) continue;
           if(coll[y]==-1){
                coll[y]=coll[x]^1;
                q.push(y);
           }
           else if(coll[y]==coll[x])
                return true;
        }
    }
    return false;
}
int main()
{
	int t;cin>>t;
	int mm;
	while(t--)
	{
		memset(m,false,sizeof(m));
		cin>>n>>mm;
		int a,b;
		for(int i=0;i<mm;++i)
		{
			cin>>a>>b;
			a--;b--;
			m[a][b]=true;
			m[b][a]=true;
		}
		memset(coll,-1,sizeof(coll));
		int i;
		for(i=0;i<n;++i)
		{
			if(coll[i]==-1)
			{coll[i]=-1;if(bfs(i))break;}
		}
		if(i==n)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
/*
3
3 2
1 2
2 3
4 3
1 2
2 3
2 4
6 7
1 2
1 3
2 3
2 4
4 5
4 6
5 6
*/
