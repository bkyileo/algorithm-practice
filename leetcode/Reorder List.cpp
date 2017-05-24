#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {
	vector<ListNode*> vec;
	while(head)
	{
		vec.push_back(head);
		head=head->next;
	}
	int step = vec.size()-1;
	int last = 0;
	int sign = -1;
	for(;step>0;step--)
	{
		//cout<<"last+sign*(-1)*step : "<<last+sign*(-1)*step<<endl;
		vec[last]->next=vec[last+sign*(-1)*step];
		last=last+sign*(-1)*step;
		sign *= -1;
	}
	vec[last]->next=NULL;
}
int main()
{	
	ListNode* a=new ListNode(1);
	ListNode* b=new ListNode(2);
	ListNode* c=new ListNode(3);
	a->next=b;b->next=c;
	reorderList(a);
	while(a)
	{
		cout<<a->val<<" ";
		a=a->next;
	}
	cout<<endl;
	return 0;
}
