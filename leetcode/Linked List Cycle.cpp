#include<bits/stdc++.h>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool hasCycle(ListNode *head) {
	if(!head) return false;
	ListNode *curr = head->next;
	while(1)
	{
		if(!curr) return false;
		if(curr==head) return true;
		curr=curr->next;
		if(!curr) return false;
		head=head->next;
	}
}

int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(1);
	cout << (a==b) <<endl;
 
	return 0;	
}
