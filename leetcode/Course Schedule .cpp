/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/ 
// 不要用自己创造的结构体 用邻接数组标示图 
#include<bits/stdc++.h>
using namespace std;
struct course
{
	int val;
	vector<int> pre;
	course(int a):val(a) {
	}
};

//dfs 递归方法没问题就是慢 
bool dfs(vector<course> temp,vector<bool> visit,int curr)
{
	if(temp[curr].pre.size()==0)
		return true;
	else if (!visit[curr])
		return false;
	else{
		visit[curr]=false;
		for(int i=0;i<temp[curr].pre.size();++i)
			if(!dfs(temp,visit,temp[curr].pre[i]))
				return false;
		return true;
	}
}

//dfs 需要使用stack 来解决 
bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites) {
	vector<course> temp;
	for(int i=0;i<numCourses;++i)
	{
		temp.push_back(course(i));
	}
	for(int i=0;i<prerequisites.size();++i)
	{
		temp[prerequisites[i].first].pre.push_back(prerequisites[i].second);
	}
	
	for(int i=0;i<temp.size();++i)
	{
		vector<bool> visit(numCourses,true);
		//vector<bool> tour(numCourses,true);
		if(!dfs(temp,visit,temp[i].val))
			return false; 
	}	
    return true;
} 

int main()
{
	vector< pair<int, int> > prerequisites;
	//[[1,0],[2,6],[1,7],[6,4],[7,0],[0,5]]
	prerequisites.push_back(make_pair(1,0));
	prerequisites.push_back(make_pair(2,6));
	prerequisites.push_back(make_pair(1,7));
	prerequisites.push_back(make_pair(6,4));
	prerequisites.push_back(make_pair(7,0));
	prerequisites.push_back(make_pair(0,5));
	cout<<canFinish(8,prerequisites)<<endl;
	return 0;
}
