# coding=utf-8
__author__ = 'BK'

'''
A robot is located at the top-left corner of a m x n grid
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid
(marked 'Finish' in the diagram below).

How many possible unique paths are there?
'''

'''
      1
    1 2 1
   1 3 3 1
  1 4 6 4 1
 1 5 10 10 5 1
'''

def getAnswer(n,m):

    m,n=max(m,n),min(m,n)
    # m+n-1 min(m,n)
    # C
    re=1
    for i in xrange(m-n+1,m+1,1):
        re *= i
    for i in xrange(1,n+1):
        re /= i

    return re

class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    def uniquePaths(self, m, n):
        if n==1:
            return 1
        elif m==1:
            return 1
        else:
            return (self.uniquePaths(n-1,m)+self.uniquePaths(n,m-1))

if __name__=='__main__':

    solu = Solution()
    # m+n-1 min(m,n)

    print getAnswer(7-2,2)
    print solu.uniquePaths(4,3)
    #for i in xrange(2,5):
    #    print i