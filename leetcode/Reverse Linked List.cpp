/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.

Subscribe to see which companies asked this question
*/ 
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* helper(ListNode* curr,ListNode* prev,ListNode* head)
{
	if (!curr->next)
	{
		curr->next=prev;
		return curr;
	}
	ListNode* next = curr->next;
	curr->next = prev;
	helper(next,curr,head);
}

ListNode* helper2(ListNode* head)
{
	if (!head)return head;
	ListNode* p=head;
	ListNode* q=head->next;
	ListNode* temp=NULL;
	p->next=NULL;
	
	while(q)
	{
		temp=q->next;
		q->next=p;
		
		p=q;
		q=temp;
	}
	return p;
}

void print(ListNode* head)
{
	if (!head)
	{
		cout<<endl;
		return;
	}
	cout<<head->val<<" ";
	print(head->next);
}

int main()
{
	ListNode* a=new ListNode(1);
	a->next=new ListNode(2);
	a->next->next=new ListNode(3);
	a->next->next->next=new ListNode(4);
	a->next->next->next->next=new ListNode(5);
	print (a);
	ListNode* head = a;
	print(helper2(head));
	//print(a);
}
