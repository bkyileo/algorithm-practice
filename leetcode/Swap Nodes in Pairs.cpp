#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* swapPairs(ListNode* head) {
        if(!head)return NULL;
    	ListNode *odd=new ListNode(-1);
    	ListNode *even=new ListNode(-1);
    	ListNode *odd2=odd;
    	ListNode *even2=even;
    	int ct=1;
    	while(head)
    	{
    		if(ct%2)
    		{
    			odd2->next=head;
    			head=head->next;
    			odd2=odd2->next;
    			odd2->next=NULL;
    		}
    		else
    		{
    			even2->next=head;
    			head=head->next;
    			even2=even2->next;
    			even2->next=NULL;
    		}
    		ct++;
    		//cout<<"here"<<endl;
    	}
    	ListNode *res=new ListNode(-1);
    	ListNode *res2=res;
    	odd=odd->next;
    	even=even->next;
    	while(odd&&even)
    	{
    		//cout<<"here1"<<endl;
    		res2->next=even;
    		even=even->next;
    		res2=res2->next;
    		
    		res2->next=odd;
    		odd=odd->next;
    		res2=res2->next;		
    	}
    	if(odd)res2->next=odd;
    	if(even)res2->next=even;
    	return res->next;  
}
int main()
{
	ListNode *t1=new ListNode(1);
	ListNode *t2=new ListNode(2);
	t1->next=t2;
	ListNode *t3=swapPairs(t1);
	while(t3)
	{
		cout<<t3->val<<" ";
		t3=t3->next;
		
	}
	return 0;
}
