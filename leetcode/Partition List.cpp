//Partition List My Submissions Question
//Total Accepted: 61125 Total Submissions: 210178 Difficulty: Medium
//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.
//
//Subscribe to see which companies asked this question
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void tral(ListNode* head)
	{
		if (head==NULL)
		{	cout<<endl ;
			return ;
		}
		else
		{
			cout<<head->val<<" ";
			this->tral(head->next);
		} 
	}
    ListNode* partition(ListNode* head, int x) {
    	
		if (head==NULL)
			return head; 
    	
		ListNode* left = new ListNode(-1);
    	ListNode* right = new ListNode(-1);
    	ListNode* leftt = left;
    	ListNode* rightt = right;
    	
    	while (head!=NULL)
    	{
    		if (head->val<x)
    		{
    			left->next=head;
    			head=head->next;
    			left=left->next;
    			left->next=NULL;
			}
			else
			{
				right->next=head;
				head=head->next;
    			right=right->next;
    			right->next=NULL;
			}	
		}
		left->next=rightt->next;
		return leftt->next;
    }
};
int main()
{
	ListNode a(1);ListNode b(4);ListNode c(3);ListNode d(2);ListNode e(5);ListNode f(2);
	a.next=&b;b.next=&c;c.next=&d;d.next=&e;e.next=&f;
	Solution solu;
	solu.tral(&a);
	solu.tral(solu.partition(&a,3));
	
}

