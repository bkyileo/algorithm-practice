__author__ = 'BK'
'''
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Subscribe to see which companies asked this question

Show Tags
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        res=head

        if head==None or head.next==None :
            return head

        fast=head.next
        slow=head

        while fast!=None:
            if fast.val == slow.val:
                fast=fast.next
                slow.next=fast
            else:
                slow=slow.next
                fast=fast.next

        return res

def tral(head):
    print head.val
    if head.next!=None:
        tral(head.next)

a=ListNode(1)
b=ListNode(1)
c=ListNode(2)
d=ListNode(3)
e=ListNode(3)
a.next=b
b.next=c
c.next=d
d.next=e

tral(a)
solu = Solution()
tral(solu.deleteDuplicates(a))

