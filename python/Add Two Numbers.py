# coding=utf-8
__author__ = 'BK'

'''
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l1List=[l1.val]
        while (l1.next != None):
            l1List.append(l1.next.val)
            l1=l1.next

        l2List=[l2.val]
        while (l2.next != None):
            l2List.append(l2.next.val)
            l2=l2.next
        l1List.reverse()
        l2List.reverse()

        a=0
        b=0

        for i in l1List:
            a=a*10+i
        for i in l2List:
            b=b*10+i

        re=str(a+b)
        relist=[]

        for i in xrange(len(re)):
            print int(re[len(re)-i-1])
            relist.append(ListNode(int(re[len(re)-i-1])))
        for i in xrange(len(relist)):
            if i+1<len(relist):
                relist[i].next=relist[i+1]
            else:
                return relist[0]


lv2=ListNode(2)
lv4=ListNode(4)
lv3=ListNode(3)
lv2.next=lv4
lv4.next=lv3

rv5=ListNode(5)
rv6=ListNode(6)
rv4=ListNode(4)
rv5.next=rv6
rv6.next=rv4

solu=Solution()