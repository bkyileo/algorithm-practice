// leetcode Minimum Height Trees
#include<bits/stdc++.h>
using namespace std;

void bfs(vector< vector<int> > graph,int i,vector<int> &res,int &minh)
{
	vector<bool> visit(graph.size(),false);
	
	int height=0;
	vector<int> pre;
	
	pre.push_back(i);
	visit[i]=true;
	int now;
	while(!pre.empty())
	{
		vector<int> curr;
		for(int i=0;i<pre.size();++i)
		{
			now=pre[i];
			for(int j=0;j<graph[now].size();++j)
			{	
				if(visit[graph[now][j]]) 
					continue;
				curr.push_back(graph[now][j]);
				visit[graph[now][j]]=true;
			}
		}
		pre=curr;
		height+=1;
		if(height>minh)return; 
	}
	
	if(height==minh)
	{
		res.push_back(i);
	}
	
	if(height<minh)
	{
		res.clear();
		res.push_back(i);
		minh=height;
	}

	//graph[i]
	return ;
}
//对于每一个图的节点 都进行bfs 求每一个根的长度 TLE 
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	vector< vector<int> > graph(n);
	//clone graph
	for(auto e:edges)
	{
		graph[e.first].push_back(e.second);
		graph[e.second].push_back(e.first);
	}
	vector< int > res;
	int minh=INT_MAX;
	
	
	for(int i=0;i<n;++i)
	{
		bfs(graph,i,res,minh);
	}
	
	return res;        
}
int main()
{
	//n = 4, edges = [[1, 0], [1, 2], [1, 3]]
	//n = 6 [0, 3], [1, 3], [2, 3], [4, 3], [5, 4]
	int n=6; 
	vector<pair<int, int>> edges;
	edges.push_back(make_pair(0,3));
	edges.push_back(make_pair(1,3));
	edges.push_back(make_pair(2,3));
	edges.push_back(make_pair(4,3));
	edges.push_back(make_pair(5,4));
	
	vector<int> res=findMinHeightTrees(n,edges);
	for(auto i:res)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}

//利用拓扑排序解，太屌了 
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<int> ans;
    if(!n)
       return ans;
    if(n == 1)
    {
        ans.push_back(0);
        return ans;
    }
    vector<unordered_set<int>> v(n);
    for(int i = 0; i < edges.size();++i)
    {
       v[edges[i].first].insert(edges[i].second);
       v[edges[i].second].insert(edges[i].first);
    }
    vector<int> leaves;
    for(int i = 0; i < n; ++i)
       if(v[i].size() == 1)
          leaves.push_back(i);
    while(true)
    {
        vector<int> newleaves;
        for(int l : leaves)
        {
             for(int i : v[l])
             {
                 v[i].erase(l);
                 if(v[i].size() == 1)
                    newleaves.push_back(i);
             }
        }
        if(newleaves.size() == 0)
           return leaves;
        leaves = newleaves;
    }
}
