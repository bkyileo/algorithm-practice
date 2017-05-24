# coding=utf-8
__author__ = 'BK'
'''
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

'''

# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    # LTE solution 浪费时间感觉主要来自 开辟新的Interval
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals)<2:
            return intervals
        intervals = sorted(intervals, key = lambda x: x.start)
        for i in xrange(len(intervals)-1,0,-1):
            if intervals[i].start<=intervals[i-1].end:
                new=Interval(intervals[i-1].start,intervals[i].end)
                intervals.remove(intervals[i])
                intervals[i-1] = new
        return intervals
    #AC solution
    def merge2(self, intervals):
        r = []
        for i in sorted(intervals, key=lambda i: i.start):
            if not r or i.start > r[-1].end:
                r.append(i)
            elif i.end > r[-1].end:
                r[-1].end = i.end
        return r

def tral(a):
    for i in a:
        print i.start,i.end
#[1,3],[2,6],[8,10],[15,18],
#a=[Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18)]
a=[Interval(1,5),Interval(2,4),Interval(3,6)]
solu = Solution()
res = solu.merge(a)
print res
tral(res)
