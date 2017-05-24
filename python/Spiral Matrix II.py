__author__ = 'BK'
'''
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
'''

class Solution(object):

    def helper(self,res,dirc,current,x,y):
        if res[x][y] != 0:
            return

        res[x][y] = current

        if  -1<x+dirc[0][0] and x+dirc[0][0]<len(res) and -1<y+dirc[0][1] and y+dirc[0][1]<len(res) and res[x+dirc[0][0]][y+dirc[0][1]] == 0:
            self.helper(res,dirc,current+1,x+dirc[0][0],y+dirc[0][1])
        else:
            dirc[0],dirc[1],dirc[2],dirc[3]=dirc[1],dirc[2],dirc[3],dirc[0]
            self.helper(res,dirc,current+1,x+dirc[0][0],y+dirc[0][1])


    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n==0:
            return []
        if n==1:
            return[[1]]

        res = [[0 for i in xrange(n)]for j in xrange(n)]
        dirc=[(0,1),(1,0),(0,-1),(-1,0)]
        self.helper(res,dirc,1,0,0)
        return res

solu = Solution()
solu.generateMatrix(1)
'''
[[1, 2, 3, 4],
[12, 13, 14, 5],
[11, 16, 15, 6],
[10, 9, 8, 7]]
'''