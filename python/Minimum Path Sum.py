# coding=utf-8
__author__ = 'BK'

'''
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
'''

class Solution:
    # @param {integer[][]} grid
    # @return {integer}
    def minPathSum(self, grid):
        m,n=len(grid),len(grid[0])
        for i in xrange(n-1):
            grid[0][i+1] += grid[0][i]
        for i in xrange(m-1):
            grid[i+1][0] += grid[i][0]

        for i in xrange(1,n):
            for j in xrange(1,m):
                grid[j][i]=grid[j][i]+min(grid[j-1][i],grid[j][i-1])

        return grid[-1][-1]


if __name__=='__main__':
    test=[[1,2,3,4,5],
          [5,4,3,2,1],
          [1,2,3,4,5]]

    solu=Solution()

    print solu.minPathSum(test)