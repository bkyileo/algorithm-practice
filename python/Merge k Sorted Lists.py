__author__ = 'BK'
'''
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.

Subscribe to see which companies asked this question
'''

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

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

            if p.val<=addNode.val and q.val>=addNode.val:
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

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists[0])==None:
            return
        for i in xrange(1,len(lists)):
            lists[i] = self.mergeTwoLists(lists[i-1],lists[i])

        return list[-1]

print len([[]])