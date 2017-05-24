//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
#include<bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
int find(vector<UndirectedGraphNode *> &vec,int x)
{
	for(int i=0;i<vec.size();++i)
		if(vec[i]->label==x)
			return i;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    set<int> labelset;
		
	UndirectedGraphNode* newnode=new UndirectedGraphNode(node->label);
        
    queue<UndirectedGraphNode *> que;
    vector<UndirectedGraphNode *> vec;
        
	UndirectedGraphNode* curr=NULL;
	UndirectedGraphNode* cp=NULL;

	que.push(node);
    vec.push_back(newnode);
        
	labelset.insert(node->label);
		
	while(!que.empty())
    {
        curr=que.front();
		cp=vec[find(vec,curr->label)];
        	
        for(int i=0;i<curr->neighbors.size();++i)
        {
        	if(labelset.count(curr->neighbors[i]->label)==0)
        	{
        		UndirectedGraphNode* node=new UndirectedGraphNode(curr->neighbors[i]->label);
        		labelset.insert(curr->neighbors[i]->label);
				
				vec.push_back(node);
				cp->neighbors.push_back(node);
				que.push(curr->neighbors[i]);
        	}
        	else
			{
        		cp->neighbors.push_back(vec[find(vec,curr->neighbors[i]->label)]);	
			}
      		
		}
			
	que.pop();
	}
	return newnode;
}
int main()
{
	return 0;
}
