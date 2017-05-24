__author__ = 'BK'

'''
Find the contiguous subarray within an array
(containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
'''


# O(1) space

def getAnswer(nums):

    locMin = locMax = gloMax = nums[0]
    for i in xrange(1, len(nums)):
        tmp = locMin

        locMin = min(locMin*nums[i], nums[i], locMax*nums[i])

        locMax = max(tmp*nums[i], nums[i], locMax*nums[i])

        gloMax = max(gloMax, locMax)

        print 'tem :' + str(tmp)
        print 'locMin' +str(locMin)
        print 'locMax' +str(locMax)
        print 'gloMin' +str(gloMax)

    return gloMax


if __name__ =='__main__':

    test=[2,3,-2,4,3,3]
    print getAnswer(test)