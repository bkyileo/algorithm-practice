__author__ = 'BK'
'''
Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        import sys
        re=sys.maxint
        print nums

        for i in xrange(len(nums)):

            left = 0
            right = len(nums)-1

            while left<i and i<right:


                if re>abs(target-nums[i]-nums[left]-nums[right]):
                    re=abs(target-nums[i]-nums[left]-nums[right])
                    output=nums[i]+nums[left]+nums[right]

                if target-nums[i]-nums[left]-nums[right]>0:
                    left += 1
                    continue

                if target-nums[i]-nums[left]-nums[right]<0:
                    right -= 1
                    continue

                if target-nums[i]-nums[left]-nums[right]==0:
                    return target

        return output

solu = Solution()
S=[-1,2,1,-4]
#target = 1.
print solu.threeSumClosest(S,1)