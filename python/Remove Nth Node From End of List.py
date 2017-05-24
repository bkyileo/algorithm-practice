__author__ = 'BK'
'''
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        data=[]
        first=head
        while head != None:
            data.append(head)
            head=head.next
        if len(data)==1:
            return

        if n == 1:
            data[len(data)-2].next=None
        elif n== len(data):
            first = data[1]
        else:
            data[-n].next=None
            data[-n-1].next=data[-n+1]
        return first

def travel(first):
    if first!=None:
        print first.val
        travel(first.next)
    else:
        return

n1 = ListNode(1)
n2 = ListNode(2)
n3 = ListNode(3)
n4 = ListNode(4)
n5 = ListNode(5)

n1.next=n2
n2.next=n3
n3.next=n4
n4.next=n5


#travel(n1)
solu =Solution()
travel(solu.removeNthFromEnd(n1,3))