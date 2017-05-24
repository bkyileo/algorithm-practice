#include<bits/stdc++.h>
using namespace std;

    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    } 
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
            {
                return true;
            }
//        for(auto i:visited)
//            cout<<i<<" ";
//        cout<<endl;
//        for(auto i:onpath)
//            cout<<i<<" ";
//        cout<<endl;
        return	onpath[node] = false;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;
    }

int main()
{
	vector< pair<int, int> > prerequisites;
	//[[1,0],[2,6],[1,7],[6,4],[7,0],[0,5]]
	prerequisites.push_back(make_pair(1,0));
	prerequisites.push_back(make_pair(1,2));
	prerequisites.push_back(make_pair(1,7));
	prerequisites.push_back(make_pair(6,4));
	prerequisites.push_back(make_pair(7,0));
	prerequisites.push_back(make_pair(0,5));
	cout<<canFinish(8,prerequisites)<<endl;

	return 0;
}
