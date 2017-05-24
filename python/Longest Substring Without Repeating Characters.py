# coding=utf-8
__author__ = 'BK'
'''
Given a string, find the length of the longest substring without
repeating characters. For example, the longest substring without
repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
'''

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxLen=0
        current=0
        nums=len(s)
        charSet=set()
        for i in xrange(nums):
            if s[i] not in charSet:
                charSet.add(s[i])
                current=current+1
                print 'current '+str(current)
            else:
                maxLen=max(maxLen,current)
                print s[s[0:i].rfind(s[i]):i]
                current=len(s[s[0:i].rfind(s[i]):i])
                charSet=set(s[s[0:i].rfind(s[i]):i])
        return max(maxLen,current)


s='abba'
solu=Solution()
print solu.lengthOfLongestSubstring(s)