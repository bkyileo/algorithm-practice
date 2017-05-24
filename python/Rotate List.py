__author__ = 'BK'
'''
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Subscribe to see which companies asked this question
'''
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
def travl(head):
    if head == None:
        return
    print head.val
    travl(head.next)


class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k==0 :
            return head

        if head==None:
            return

        fast = 0
        start = head
        slow = head

        while fast != k:
            fast += 1
            if head.next ==None:
                return start
            head = head.next


        while head.next != None:
            slow = slow.next
            head = head.next

        res=slow.next
        slow.next=None
        head.next = start
        return res

a = ListNode(0)
b = ListNode(1)
c = ListNode(2)
d = ListNode(3)
e = ListNode(4)
f = ListNode(5)
a.next = b
b.next = c
c.next = d
d.next = e
e.next = f

travl(a)
solu = Solution()
travl(solu.rotateRight(a,1))