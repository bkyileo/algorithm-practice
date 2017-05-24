__author__ = 'BK'

'''
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
'''

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        visited = [[0] * len(grid[0]) for row in range(len(grid))]

        count=0
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j]=='1' and visited[i][j]==0 :
                    count=count+1
                    self.dfs(i,j,grid,visited)
        return count

    def dfs(self, m, n, grid, visited):

        if visited[m][n] == 0 and grid[m][n] == '1':
            visited[m][n] = 1

            if m < (len(grid) - 1):
                self.dfs(m + 1, n, grid, visited)
            if n < (len(grid[0]) - 1):
                self.dfs(m, n + 1, grid, visited)
            if m > 0:
                self.dfs(m - 1, n, grid, visited)
            if n > 0:
                self.dfs(m, n - 1, grid, visited)
        else:
            return;


Solu = Solution()

test = ['11000',
        '11000',
        '00100',
        '00011']

Solu.numIslands(test)
