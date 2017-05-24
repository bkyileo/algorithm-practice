# coding=utf-8
__author__ = 'BK'
'''
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

Subscribe to see which companies asked this question
'''

#可以考虑用分治的思想解决这个问题，但是意义不大

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        lenth=len(matrix)
        import copy
        temp = copy.deepcopy(matrix)
        for i in xrange(lenth):
            for j in xrange(lenth):
                matrix[j][lenth-1-i]=temp[i][j]

solu = Solution()
a=[[1,2,3,4,5],
   [1,2,3,4,5],
   [1,2,3,4,5],
   [1,2,3,4,5],
   [1,2,3,4,5]]
solu.rotate(a)
print a