# coding=utf-8
__author__ = 'BK'

'''
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        count=nums.count(val)

        for i in xrange(count):
            nums.remove(val)

        return len(nums)

#考虑存储数字 而不是删除数字

a=[1,2,1,3,4,5]
solu = Solution()
print solu.removeElement(a,1)
print a