#coding=utf-8
__author__ = 'BK'
'''

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

'''

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        # bug free

        re=[]
        nums.sort()

        for i in xrange(len(nums)):

            left = 0
            right = len(nums)-1

            while left < i and i<right:

                if nums[i]+nums[left]+nums[right]>0:
                    right -= 1
                    continue
                elif nums[i]+nums[left]+nums[right]<0:
                    left += 1
                    continue
                else:

                    #下面这一句怎么优化？

                    if [nums[left],nums[i],nums[right]] not in re:
                        re.append([nums[left],nums[i],nums[right]])
                    left += 1

        return re

solu=Solution()
S = [-1,0,1,2,-1,-4]
print solu.threeSum(S)

