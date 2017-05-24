# coding=utf-8
__author__ = 'BK'
# 中位数
'''
Median is the middle value in an ordered integer list.
If the size of the list is even, there is no middle value.
So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
'''

class MedianFinder:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.seq=[]
        self.nums=0

    def addNum(self, num):
        """
        Adds a num into the data structure.
        :type num: int
        :rtype: void
        """
        if self.nums==0:
            self.seq=[num]
            self.nums=1
        else:
            index=0
            for i in xrange(self.nums):
                if num > self.seq[i]:
                    index=index+1
                else:
                    break
            self.seq.insert(index,num)
            self.nums=self.nums+1

    def findMedian(self):
        """
        Returns the median of current data stream
        :rtype: float
        """
        if self.nums==1:
            return self.seq[0]

        if self.nums%2==0:
            return float(self.seq[self.nums/2]+self.seq[self.nums/2-1])/2
        else:
            return float(self.seq[self.nums/2])

mf = MedianFinder()

mf.addNum(6)
print mf.findMedian()
mf.addNum(10)
print mf.findMedian()
mf.addNum(2)
print mf.findMedian()
mf.addNum(6)
print mf.findMedian()
mf.addNum(5)
print mf.findMedian()
mf.addNum(0)
print mf.findMedian()
