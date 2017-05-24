__author__ = 'BK'
'''
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.

Subscribe to see which companies asked this question
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        if l1==None:
            return l2
        if l2==None:
            return l1

        if l1.val>l2.val:
            basicNode =  l2
            addNode = l1
        else:
            basicNode = l1
            addNode = l2

        p = basicNode
        q = basicNode.next

        r = addNode.next

        while 1 :

            if q == None:
                p.next = addNode
                break

            if p.val<= addNode.val and q.val>addNode.val:
                p.next = addNode
                addNode.next = q
                p = addNode
                addNode = r

                if addNode==None:
                    break
                else:
                    r = r.next

            else:
                p = q
                q = q.next

        return basicNode


n1 = ListNode(1)
n3 = ListNode(3)
n5 = ListNode(5)
n7 = ListNode(7)
n9 = ListNode(9)

n1.next=n3
n3.next=n5
n5.next=n7
n7.next=n9

n2 = ListNode(2)
n4 = ListNode(4)
n6 = ListNode(6)
n8 = ListNode(8)
n10 = ListNode(10)
n12 = ListNode(12)

n2.next=n4
n4.next=n6
n6.next=n8
n8.next=n10
n10.next=n12

solu = Solution()
node=solu.mergeTwoLists(n1,n2)

def travel(first):
    if first!=None:
        print first.val
        travel(first.next)
    else:
        return

travel(node)