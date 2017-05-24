__author__ = 'BK'

def lengthOfLIS(nums):
    if len(nums)==0:
        return 0
    maxlenth=1
    re=[1]*len(nums)
    for i in xrange(len(nums)):
        currentMax=1
        for j in xrange(i):
            if nums[i]>nums[j]:
                currentMax=max(currentMax,re[j]+1)
        re[i]=currentMax
    return max(re)

print lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18])