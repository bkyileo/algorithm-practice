struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int diff=0;
	ListNode *a = headA;
	ListNode *b = headB;
	while(a&&b)
	{
		a=a->next;
		b=b->next; 
	}
	if(a&&!b)
	{
		while(a)
		{
			diff++;
			a=a->next;
		}
		while(diff--)
		{
			headA=headA->next;
		}
		while(headA)
		{
			if(headA==headB)
				return headA;
			headA=headA->next;
			headB=headB->next;
		}
	}
	if(!a&&b)
	{
		while(b)
		{
			diff++;
			b=b->next;
		}
		while(diff--)
		{
			headB=headB->next;
		}
		while(headA)
		{
			if(headA==headB)
				return headA;
			headA=headA->next;
			headB=headB->next;
		}	
	}
	while(headA)
	{
		if(headA==headB)
			return headA;
		headA=headA->next;
		headB=headB->next;
	}
}
