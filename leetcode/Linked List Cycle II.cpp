#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	if(!head) return NULL;
	
	ListNode * curr=head;
	ListNode * slow=head;

	while(1)
	{
		head=head->next;
		curr=curr->next;
		if(!curr) return NULL;
		curr=curr->next;
		if(!curr) return NULL;
		if(curr==head) break;
	}
	
	while(slow!=curr)
	{
		solw=solw->next;
		curr=curr->next;
	}
	
	return slow;
	
} 
