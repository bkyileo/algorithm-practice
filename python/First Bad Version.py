__author__ = 'BK'
'''
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
'''
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):
def isBadVersion(n):
    return True

class Solution(object):
    def helper(self,left,right):
        if left==right-1:
            if isBadVersion(left):
                return left
            else:
                return right

        mid=(left+right)/2

        if isBadVersion(mid):
            return self.helper(left,mid)
        else:
            return self.helper(mid,right)

    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==1:
            return 1
        left=1
        right=n
        return self.helper(left,right)