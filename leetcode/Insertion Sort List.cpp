#include<bits/stdc++.h>
using namespace std;
// Sort a linked list using insertion sort.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* insertionSortList(ListNode* head) {
	if(!head) return NULL;
	vector<ListNode*> temp;
	temp.push_back(head);
	head=head->next;
	while(head)
	{
		vector<ListNode*>::iterator find=temp.begin();
		for(;find!=temp.end();++find)
		{
			//cout<<head->val<<" "<<(*find)->val<<endl;
			if(head->val<(*find)->val)
			{
				temp.insert(find,head);
				break;
			}
		}
		if(find==temp.end())
			temp.insert(find,head);
		head=head->next;
	}
	for(int i=0;i<temp.size()-1;++i)
	{
		temp[i]->next=temp[i+1];
	}
	temp[temp.size()-1]->next=NULL;
	return temp[0];
}

int main()
{
	ListNode* a = new ListNode(3);
	ListNode* b = new ListNode(2);
	//ListNode* c = new ListNode(4);
	
	a->next=b;
	//b->next=c;
	ListNode* d=insertionSortList(a);
	
	while(d)
	{
		cout<<d->val<<" ";
		d=d->next;
	}
	cout<<endl;
	
	return 0;
}
