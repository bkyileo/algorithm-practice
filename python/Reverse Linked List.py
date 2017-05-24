__author__ = 'BK'
'''
Reverse a singly linked list.

click to show more hints.

Subscribe to see which companies asked this question
'''
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head :return head
        p,q=head,head.next
        p.next=None

        while q:
            temp,q.next=q.next,p
            p,q=q,temp
        return p

def tral(node):
    if node:
        print node.val
        tral(node.next)

solu = Solution()
a=ListNode(1)
b=ListNode(2)
c=ListNode(3)
d=ListNode(4)
e=ListNode(5)
a.next=b
b.next=c
c.next=d
d.next=e
tral(a)

tral(solu.reverseList(a))