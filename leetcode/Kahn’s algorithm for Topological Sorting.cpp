#include<bits/stdc++.h>
using namespace std;
//Kahn¡¯s algorithm for Topological Sorting

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector< int > graph(numCourses,0);
	for(auto edge:prerequisites)
	{
		graph[edge.first]++;
	}
	queue<int> q;
	int count=0;
	vector<int> res; 
	for(int i=0;i<graph.size();++i)
	{
		if(graph[i]==0)
		{
			q.push(i);
			count++;
		}
	}
	while(!q.empty())
	{
		int top=q.front();
		res.push_back(top);
		q.pop();
		for(auto edge:prerequisites)
		{
			if(edge.second==top)
			{
				graph[edge.first]--;
				if(graph[edge.first]==0)
				{
					q.push(edge.first);
					count++;
				}	
			}
		}
	}
	return count==numCourses;
} 
int main()
{
	vector< pair<int, int> > prerequisites;
	//[[1,0],[2,6],[1,7],[6,4],[7,0],[0,5]]
	prerequisites.push_back(make_pair(1,0));
	prerequisites.push_back(make_pair(0,1));
//	prerequisites.push_back(make_pair(1,7));
//	prerequisites.push_back(make_pair(6,4));
//	prerequisites.push_back(make_pair(7,0));
//	prerequisites.push_back(make_pair(0,5));
	cout<<canFinish(8,prerequisites)<<endl;
	return 0;
}
