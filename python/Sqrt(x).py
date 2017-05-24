__author__ = 'BK'
'''
Implement int sqrt(int x).

Compute and return the square root of x.

Subscribe to see which companies asked this question
'''

class Solution(object):

    def helper(self,left,right,target):
        mid = (left+right)/2
        if mid==left:
            return mid
        if mid*mid<=target:
            return self.helper(mid,right,target)
        else:
            return self.helper(left,mid,target)

    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==1:return 1
        return self.helper(0,x,x)

solu = Solution()

print solu.mySqrt(100)