# coding=utf-8
__author__ = 'BK'
'''
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

Subscribe to see which companies asked this question
'''

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if not head:return head
        pos=head
        for i in xrange(1,m-1):
            pos=head.next

        p,q=pos.next,pos.next.next
        temp2=p
        p.next=None
        for i in xrange(m,n-1):
            temp,q.next=q.next,p
            p,q=q,temp
        pos.next=q
        temp2.next=p

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
#solu.reverseBetween(a,2,4)
tral(solu.reverseBetween(a,2,4))