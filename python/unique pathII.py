# coding=utf-8
__author__ = 'BK'
'''
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
'''
        #没有考虑1维度的情况
'''
        m,n =len(obstacleGrid[0]),len(obstacleGrid)

        if obstacleGrid[0][0]==1:
            return 0

        if n==1:
            for i in xrange(0,m):
                if obstacleGrid[0][i]==1:
                    return 0
                else :
                    continue
            return 1

        if m==1:
            for i in xrange(0,n):
                if obstacleGrid[i][0]==1:
                    return 0
                else :
                    continue
            return 1

        for i in xrange(0,m):
            if obstacleGrid[0][i] != 1:
                obstacleGrid[0][i] = 1
            else :
                obstacleGrid[0][i] = 0
                break

        for i in xrange(1,n):
            if obstacleGrid[i][0] != 1:
                obstacleGrid[i][0] = 1
            else :
                obstacleGrid[i][0] = 0
                break

        print obstacleGrid

        for i in xrange(1,n):
            for t in xrange(1,m):
                if obstacleGrid[i][t]==1:
                    obstacleGrid[i][t]=0
                elif obstacleGrid[i][t]== 0:
                    obstacleGrid[i][t]=obstacleGrid[i-1][t]+obstacleGrid[i][t-1]


        print obstacleGrid
        return obstacleGrid[-1][-1]
'''

class Solution:
    # @param {integer[][]} obstacleGrid
    # @return {integer}
    def uniquePathsWithObstacles(self, obstacleGrid):

        if not obstacleGrid:
            return
        r, c = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0 for _ in xrange(c)] for _ in xrange(r)]
        dp[0][0] = 1 - obstacleGrid[0][0]
        for i in xrange(1, r):
            dp[i][0] = dp[i-1][0] * (1 - obstacleGrid[i][0])
        for i in xrange(1, c):
            dp[0][i] = dp[0][i-1] * (1 - obstacleGrid[0][i])
        for i in xrange(1, r):
            for j in xrange(1, c):
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) * (1 - obstacleGrid[i][j])
        return dp[-1][-1]

    #利用减法和乘法赋值


if __name__=='__main__':
     solu = Solution()
    # # m+n-1 min(m,n)
     test=[[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[1,0],[0,0],[0,0],[0,0],[0,0],[0,0],[1,0],[0,0],[0,0],[0,0],[0,0],[0,1],[0,0],[0,0],[1,0],[0,0],[0,0],[0,1],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,1],[0,0],[0,0],[0,0],[0,0],[1,0],[0,0],[0,0],[0,0],[0,0]]
     print test[1][0]
     print solu.uniquePathsWithObstacles(test)