__author__ = 'BK'
'''
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Subscribe to see which companies asked this question
'''

class Solution(object):

    def helper(self,nums,start,re):
        import copy
        if start == len(nums):
            if nums not in re:
                re.append(copy.copy(nums))
            return

        for i in xrange(start,len(nums)):

            nums[i],nums[start]=nums[start],nums[i]
            self.helper(nums,start+1,re)
            nums[i],nums[start]=nums[start],nums[i]

    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        re=[]
        self.helper(nums,0,re)
        return re

solu = Solution()
nums=[1,1,0,0,1,-1,-1,1]
print solu.permute(nums)
