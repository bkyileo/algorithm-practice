# coding=utf-8
__author__ = 'BK'
'''
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2. Please note that your returned answers
(both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Subscribe to see which companies asked this question
'''
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d={}
        for i,v in enumerate(nums):
            if target-v in d:
                return [d[target-v],i+1]
            d[v]=i+1

        #  ↑ 方法用了一次遍历 字典管理 key value 互换
        #  ↓ 方法出了一次遍历之外还增加了一次查询（index） 所以慢了一些

        # for i in xrange(len(nums)):
        #     if (target-nums[i]) in nums[i+1:]:
        #         nums.reverse()
        #         return [i+1,len(nums)-nums.index(target-nums[len(nums)-i-1])]
        # return None


solu=Solution()
nums={1:1,2:2,3:3}
print type(nums)
target=0

print solu.twoSum(nums,target)

