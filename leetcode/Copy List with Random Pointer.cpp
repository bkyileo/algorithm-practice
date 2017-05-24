#include<bits/stdc++.h>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	if(!head) return head;
	vector< RandomListNode *>nodes;
	
	RandomListNode * curr = head->next;
	RandomListNode * pre = new RandomListNode(head->label);
	nodes.push_back(pre);
	head->label=0;
	while(curr)
	{
		RandomListNode * n = new RandomListNode(curr->label);
		nodes[nodes.size()-1]->next = n;
		curr->label = nodes.size();
		nodes.push_back(n);
		curr = curr->next;
	}
	
	curr = head;
	int i=0;
	while(curr)
	{
		nodes[i]->random=nodes[curr->random->label];
		curr=curr->next;
		i++;
	}
	return nodes[0];	
} 

int main()
{
	return 0;
}
