#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* merge(ListNode* a,ListNode* b) {
	ListNode* tp=new ListNode(-1);
	ListNode* curr=tp;
	while(a&&b)
	{
		if(a->val<b->val)
		{
			curr->next=a;
			a=a->next;
		}
		else
		{
			curr->next=b;
			b=b->next;			
		}
		curr=curr->next;
	}
	if(a){curr->next=a;}
	if(b){curr->next=b;}
	return tp->next;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
	
	while(lists.size()>1)
	{
		vector<ListNode*> next;
		for(int i=0;i<lists.size()/2;++i)
		{
			next.push_back(merge(lists[2*i],lists[2*i+1]));
		}
		if(lists.size()%2)
		{
			next.push_back(lists[lists.size()-1]);
		}
		lists=next;
	}
	return lists[0];
}
int main()
{
	ListNode* t0=new ListNode(0);
	ListNode* t1=new ListNode(1);
	ListNode* t2=new ListNode(2);
	ListNode* t3=new ListNode(3);
	ListNode* t4=new ListNode(4);
	
	//t0->next=t1;//t1->next=t2;
	//t2->next=t3;t3->next=t4;
	
	vector<ListNode*> lists;
	lists.push_back(t0);
	lists.push_back(t1);
	lists.push_back(t2);
	lists.push_back(t3);
	lists.push_back(t4);
	ListNode* curr=mergeKLists(lists);
	while(curr){
		cout<<curr->val<<" ";
		curr=curr->next;
	}
	cout<<endl;
	return 0;
}
