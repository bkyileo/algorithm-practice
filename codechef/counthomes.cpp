#include<bits/stdc++.h>
using namespace std;
int lruCountMiss(int max_cache_size,int *pages,int len)
{
	int res=0;
	vector<int> vct;
	for(int i=0;i<len;++i)
	{
		if(find(vct.begin(),vct.end(),pages[i])!=vct.end())
		{
			vct.erase(find(vct.begin(),vct.end(),pages[i]));
			vct.push_back(pages[i]);
			continue;
		}
		if(vct.size()<max_cache_size)
		{
			vct.push_back(pages[i]);
			continue;	
		}
		else
		{
			res++;
			vct.erase(vct.begin());
			vct.push_back(pages[i]);
			continue;
		}
	}
	return res;
}
void dfs(int **grid,int n,int m,int i,int j,vector<vector<bool>> &visit,int &res)
{
	if(i>=0&&i<n&&j>=0&&j<m&&grid[i][j]==1)
	{
		visit[i][j]=true;
		dfs(grid,n,m,i+1,j,visit,res);
		dfs(grid,n,m,i-1,j,visit,res);
		dfs(grid,n,m,i,j+1,visit,res);
		dfs(grid,n,m,i,j-1,visit,res);
	}
}
int CountHomes(int **grid,int n,int m)
{
	vector<vector<bool>> visit(n,vector<bool>(m,false));	
	int res=0;
	for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)
	{
		if(!visit[i][j]&&grid[i][j]==1)
		{
			dfs(grid,n,m,i,j,visit,res);
			res++;	
		}
	}
	return res;
} 
int main()
{
	return 0;
}
