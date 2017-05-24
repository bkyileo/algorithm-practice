# coding=utf-8
__author__ = 'BK'
'''
Implement strStr().

Returns the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if haystack=='' and needle=='':
            return 0

        lenth=len(needle)

        for i in xrange(len(haystack)-lenth+1):
            print haystack[i:i+lenth],needle
            if haystack[i:i+lenth] == needle:
                return i
        return -1

a="mississippi"
b="issi"

solu = Solution()
print solu.strStr(a,b)
