__author__ = 'BK'
'''
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

Subscribe to see which companies asked this question
'''
# Definition for singly-linked list.

def tral(head):
    print head.val
    if head.next!=None:
        tral(head.next)

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
        if head==None or head.next==None:
            return head

        if head.next.next==None:
            if head.val==head.next.val:return None
            else:return head

        front = head.next.next
        mid = head.next
        behand = head

        start = ListNode(-1)
        res = start

        if behand.val!=mid.val:
            start.next=behand
            start=start.next


        while front != None:

            if behand.val!=mid.val and mid.val != front.val:
                start.next=mid
                start=start.next

            behand = behand.next
            mid = mid.next
            front = front.next

        if mid.val!=behand.val:
            start.next=mid
        else:
            start = res.next
            behand = res
            while start!=None:
                if start.val == start.next.val:
                    behand.next = None
                    break
                start=start.next
                behand=behand.next

        return res.next

a=ListNode(1)
b=ListNode(1)
c=ListNode(1)
d=ListNode(2)
# e=ListNode(5)
# f=ListNode(6)
# g=ListNode(7)

a.next=b
b.next=c
c.next=d
# d.next=e
# e.next=f
# f.next=g

tral(a)
solu = Solution()
tral(solu.deleteDuplicates(a))
