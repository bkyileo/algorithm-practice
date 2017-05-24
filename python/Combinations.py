__author__ = 'BK'
'''
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Subscribe to see which companies asked this question
'''

class Solution(object):
    def helper(self,n,current,k,re,temp):

        if k==0:
            re.append(temp)
            return

        if current>n:
            return

        self.helper(n,current+1,k,re,temp)
        self.helper(n,current+1,k-1,re,temp+[current])


    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        temp=[]
        res=[]
        self.helper(n,1,k,res,temp)

        return res

solu = Solution()
print solu.combine(4,2)
