# coding=utf-8
__author__ = 'BK'
'''
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2.
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def greedy(self,nums,step,range):

        #递归时候 可能会栈内存不够用 所以建议用循环
        #A=[2,3,1,1,4] [5,4,3,2,1,1,0]
        if range[0]==range[1]:return False
        maxRange=range[1]
        if maxRange>len(nums)-2:
            #return step
            return True
        for i in xrange(range[0],range[1]+1):
            maxRange=max(maxRange,i+nums[i])

        return self.greedy(nums,step+1,(range[1],maxRange))

    def jump(self, nums):

        res = 0
        edge = 0
        maxEdge = 0
        for i in range(len(nums)):
            if i > edge:
                edge = maxEdge
                res += 1
            maxEdge = max(maxEdge,i+nums[i])
        return res

    def bfs(self,nums):
        if len(nums)<2:
            return 0

        import sys
        mask = [sys.maxint]*len(nums)
        mask[0] = 0
        #最差情况是双重循环
        for i in xrange(len(nums)):
            for j in xrange(nums[i],0,-1):
                #print mask,i,j
                if i+j >= len(nums)-1:
                    return mask[i]+1
                mask[i+j]=min(mask[i+j],mask[i]+1)

solu = Solution()

#A=[1,1]
A=[5,4,3,2,1,1,1,1]
#A=[3,2,1]
print solu.jump(A)