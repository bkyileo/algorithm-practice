__author__ = 'BK'
class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.nums=nums
        for i in xrange(1,len(self.nums)):
            self.nums[i]=self.nums[i]+self.nums[i-1]

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        print self.nums
        if i<=j :
            return 0
        if i==0 :
            return self.nums[j]
        return self.nums[j]-self.nums[i-1]
nums=[-2,0,3,-5,2,-1]
solu = NumArray(nums)
print solu.nums
print solu.sumRange(0,2)
print solu.sumRange(2,5)
print solu.sumRange(0,5)