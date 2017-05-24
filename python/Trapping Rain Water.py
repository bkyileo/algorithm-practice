# coding=utf-8
__author__ = 'BK'
'''
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
算法思路：
初始化一个队列 num
从头开始读这一个height

step：找第一个非零元素入队列[0]
向右扫描数组
if height[i]<num[0] : 入队列
if height[i]>=num[0] : 入队列 && 面积进行结算 s += (len(nums)-2) * num[0] - sum(nums[1:]) num=num[-1]

最后的num进行结算:将nums 转置可以保证最后剩一个元素
再进行一遍

'''


class Solution(object):
    def helper(self,nums,s):
        s += (len(nums)-2) * nums[0] - sum(nums[1:len(nums)-1])
        nums = [nums[-1]]
        return nums,s

    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        nums=[];s=0;start=len(height)
        for i,j in enumerate(height):
            if j>0:
                nums.append(j)
                start=i
                break

        for i in xrange(start+1,len(height)):
            nums.append(height[i])
            if height[i]>=nums[0]:
                s += (len(nums)-2) * nums[0] - sum(nums[1:len(nums)-1])
                nums = [nums[-1]]

        nums.reverse()
        height = nums
        nums=[]

        for i,j in enumerate(height):
            if j>0:
                nums.append(j)
                start=i
                break

        for i in xrange(start+1,len(height)):
            nums.append(height[i])
            if height[i]>=nums[0]:
                s += (len(nums)-2) * nums[0] - sum(nums[1:len(nums)-1])
                nums = [nums[-1]]
        return s

solu = Solution()
height=[2]
print solu.trap(height)

# a=[1,2,3,4,5]
# a.reverse()
# print a