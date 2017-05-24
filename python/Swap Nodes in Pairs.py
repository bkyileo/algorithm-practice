__author__ = 'BK'
'''
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space.
You may not modify the values in the list, only nodes itself can be changed.

Subscribe to see which companies asked this question
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def travel(first):
    if first!=None:
        print first.val
        travel(first.next)
    else:
        return

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None:
            return

        if head.next==None:
            return head

        if head.next.next==None:
            start=head.next
            start.next=head
            head.next=None
            return start


        p=ListNode(1)
        p.next=head
        q=p.next
        r=q.next
        s=r.next

        start = head.next

        while 1:


            q.next=s
            p.next=r
            r.next=q
            q,r=r,q

            if s.next == None or s.next.next==None:
                break
            else:
                s=s.next.next

            p=p.next.next
            q=q.next.next
            r=r.next.next

        if s.next!=None:
            p=s.next
            r.next=p
            p.next=s
            s.next=None

        return start



n1 = ListNode(1)
n2 = ListNode(2)
n3 = ListNode(3)
n4 = ListNode(4)
n5 = ListNode(5)
n6 = ListNode(6)

# n1.next=n2
# n2.next=n3
# n3.next=n4
# n4.next=n5
# n5.next=n6


solu = Solution()
node=solu.swapPairs(n1)
travel(node)