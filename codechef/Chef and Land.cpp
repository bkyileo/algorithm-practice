//code chef Chef and Land
#include<bits/stdc++.h>
using namespace std;
int n,m;
char maze[25][25];
bool visit[25][25];
vector<char> curr;
map<char,pair<int,int>> mp;
pair<int,int> reach(pair<int,int> s,string order)
{
	pair<int,int> res=s;
	for(auto i:order)
	{
		int nextx=res.first+mp[i].first;
		int nexty=res.second+mp[i].second;
		if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&maze[nextx][nexty]=='.')
		{
			res.first=nextx;
			res.second=nexty;		
		}
		if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&maze[nextx][nexty]=='C')
		{
			res.first=nextx;
			res.second=nexty;
			return res;		
		}
	}
	return res;
}
bool findpath(pair<int,int> s)
{
	int currx=s.first;
	int curry=s.second;
	if(currx<0||currx>=n||curry<0||curry>=m||maze[currx][curry]=='*'||visit[currx][curry])return false;
	if(maze[currx][curry]=='C')return true;
	visit[currx][curry]=true;
	for(auto i:mp)
	{
		curr.push_back(i.first);
		if(findpath(make_pair(currx+i.second.first,curry+i.second.second)))return true;
		else
		{
			curr.pop_back(); 
		} 
	}
	return false;
}
int main()
{
	mp['U']=make_pair(-1,0);
	mp['D']=make_pair(1,0);
	mp['L']=make_pair(0,-1);
	mp['R']=make_pair(0,1);
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>maze[i][j];
		}
	}
	string res="";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(maze[i][j]=='.')
			{
				pair<int,int> p=reach(make_pair(i,j),res);
				curr.clear();
				memset(visit,false,sizeof(visit));
				findpath(p);
				for(auto k:curr)
				{
					res=res+k;
				}
			}
		}
	}
	cout<<res<<endl;
	return 0;
} 
