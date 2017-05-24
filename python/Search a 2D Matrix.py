__author__ = 'BK'
'''
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
'''

class Solution(object):

    def searchRow(self, matrix, target,left,right):

        mid = (left+right)/2
        if mid == left :return mid

        if matrix[mid][0] <= target:return self.searchRow(matrix,target,mid,right)
        else:return self.searchRow(matrix,target,0,mid)

    def searchCol(self,nums, target,left,right):
        mid = (left+right)/2
        if mid == left :return nums[mid]

        if nums[mid] <= target:return self.searchCol(nums,target,mid,right)
        else:return self.searchCol(nums,target,0,mid)


    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        n = len(matrix)
        index = self.searchRow(matrix,target,0,n)
        m = len(matrix[0])
        num = self.searchCol(matrix[index],target,0,m)
        if num == target:return True
        else:return False


solu = Solution()
s=[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
print solu.searchMatrix(s,6)
