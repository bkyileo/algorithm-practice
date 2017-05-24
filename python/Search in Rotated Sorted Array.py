__author__ = 'BK'
'''
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

'''
class Solution(object):

    def helper(self,nums,left,right):

        mid = (left+right)/2
        if left==mid:
            return left

        leftnum = nums[left]
        rightnum = nums[right]

        if  nums[mid]>leftnum:
            return self.helper(nums,mid,right)
        if nums[mid]<rightnum:
            return self.helper(nums,left,mid)
        #[4 5 6 7 0 1 2]

    def binary_search(self,nums,left,right,target):

        mid = (left+right)/2
        if nums[mid]==target:
            return mid

        if right -left==1:
            return -1

        if  nums[mid]>target:
            return self.binary_search(nums,left,mid,target)

        else :
            return self.binary_search(nums,mid,right,target)

    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        if nums[0]<nums[len(nums)-1]:
            return self.binary_search(nums,0,len(nums),target)

        maxIndex=self.helper(nums,0,len(nums)-1)

        print maxIndex
        if target>=nums[0]:
            return self.binary_search(nums,0,maxIndex+1,target)

        if target<=nums[-1]:
            return self.binary_search(nums,maxIndex,len(nums),target)

        return -1


solu = Solution()
test1=[4,5,6,0,1,2]
test2=[1,2,3,4,5,6,7,8,9]

print solu.search(test1,0)