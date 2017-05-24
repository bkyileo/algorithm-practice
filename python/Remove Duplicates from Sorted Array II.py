__author__ = 'BK'
'''
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count=0
        for i in xrange(len(nums)-1,0,-1):
            if nums[i] == nums[i-1]:
                if count==1:
                    nums.remove(nums[i])
                else :count += 1
            else:
                count=0
        return len(nums)

solu = Solution()
nums=[1,1,1,2,2,3,3,3,3,3,4,5,6,7]
print solu.removeDuplicates(nums)
print nums

