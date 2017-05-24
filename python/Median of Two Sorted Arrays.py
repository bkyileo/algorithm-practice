__author__ = 'BK'
'''
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
'''

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        left=nums1
        right=nums2
        num=len(left)+len(right)
        result=[]
        i,j=0,0
        while i<len(left) and j<len(right):
            if left[i]<=right[j]:
                result.append(left[i])
                i+=1
            else:
                result.append(right[j])
                j+=1
        result+=left[i:]
        result+=right[j:]
        print num
        if num%2==0:
            return float(result[num/2]+result[num/2-1])/2
        else:
            return result[num/2]

solu=Solution()

a=[1]
b=[1]

print solu.findMedianSortedArrays(a,b)
