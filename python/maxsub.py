__author__ = 'BK'
'''
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.
'''

def maxsub(problem):

    count=len(problem)

    max_num=problem[0]
    localMax=problem[0]

    for i in range(1,count):

        localMax += problem[i]
        localMax=max(problem[i],localMax)
        max_num=max(localMax,max_num)


    print max_num


def sub(nums):
    old = nums[0]
    re=0

    for i in xrange(1,len(nums)):
        re,old = max(re,max(old+nums[i],nums[i])) , max(old+nums[i],nums[i])
    print re

if __name__ == '__main__':

    test1=[-2,1,-3,4,-1,2,1,-5,4]

    sub(test1)
    maxsub(test1)