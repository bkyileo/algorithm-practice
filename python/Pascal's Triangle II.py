__author__ = 'BK'
'''
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
'''

class Solution(object):

    def helper(self,n,m):
        res = 1
        for i in xrange(n-m+1,n+1):
            res *= i
        for i in xrange(1,m+1):
            res /= i
        return res
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        res=[0]*(rowIndex+1)
        for i in xrange(len(res)):
            res[i] = self.helper(rowIndex,i)
        return res

solu = Solution()
print solu.getRow(0)