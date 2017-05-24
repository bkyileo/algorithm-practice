# coding=utf-8
__author__ = 'BK'
'''
Given a triangle, find the minimum path sum from top to bottom.
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space,
where n is the total number of rows in the triangle.
'''

class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):

        size=len(triangle[-1])
        res=triangle[-1]
        for i in xrange(size-1,0,-1):
            for j in xrange(i):
                res[j]=min(res[j],res[j+1])+triangle[i-1][j]
        return res[0]




if __name__=='__main__':
    test =[
         [2],
        [3,4],  #[9,10,10,3]
       [6,5,7], #[7,6,10,3]
      [4,1,8,3] ]
    solu=Solution()
    print solu.minimumTotal(test)


